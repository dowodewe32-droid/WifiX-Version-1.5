#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "LittleFS.h"
#include <EEPROM.h>

// Panggil header project di luar extern "C"
#include "repeater.h"
#include "wifi.h"
#include "settings.h"

// Library internal LWIP untuk NAPT
#include <lwip/napt.h>
#include <lwip/dns.h>

// Gunakan include langsung tanpa path apps/
#include <dhcpserver.h>

#define NAPT 1000
#define NAPT_PORT 10

typedef struct ap_settings_t {
    char    path[33];
    char    ssid[33];
    char    password[65];
    uint8_t channel;
    bool    hidden;
    bool    captive_portal;
} ap_settings_t;

extern ap_settings_t ap_settings;
static bool state = false;
static String wifi_ssid, wifi_pass;

static void w(const char *path, String message){
    File file = LittleFS.open(path, "w");
    if(file){
        file.print(message);
        file.close();
    }
}

static String r(const char * path){
    File file = LittleFS.open(path, "r");
    if(!file || file.isDirectory()) return String();
    String content = file.readStringUntil('\n');
    file.close();
    return content;
}

static void de(const char *path){
    LittleFS.remove(path);
}

namespace repeater {
    void connect(String ssid, String pass){
        w("/ssid.txt", ssid);
        w("/pass.txt", pass);
        WiFi.mode(WIFI_AP_STA);
        WiFi.begin(ssid.c_str(), pass.c_str());
    }

    void run() {
        wifi::stopAP();
        WiFi.mode(WIFI_STA);
        wifi_ssid = r("/ssid.txt");
        wifi_pass = r("/pass.txt");
        de("/ssid.txt");
        de("/pass.txt");
        EEPROM.write(400, 0);
        EEPROM.commit();
        
        if(wifi_pass.length() < 8) WiFi.begin(wifi_ssid.c_str());
        else WiFi.begin(wifi_ssid.c_str(), wifi_pass.c_str());
        
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
        }
        
        dhcps_set_dns(0, WiFi.dnsIP(0));
        
        WiFi.softAPConfig(
            IPAddress(172, 217, 28, 254),
            IPAddress(172, 217, 28, 254),
            IPAddress(255, 255, 255, 0)
        );
        
        WiFi.softAP(ap_settings.ssid, ap_settings.password);
        
        if (ip_napt_init(NAPT, NAPT_PORT) == ERR_OK) {
            ip_napt_enable_no(SOFTAP_IF, 1);
            state = true;
        }
    }

    bool status() { return state; }
    void update_status(bool s) { state = s; }
}
