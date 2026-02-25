#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "LittleFS.h"
#include <EEPROM.h>
#include "repeater.h"
#include "wifi.h"
#include "settings.h"

// Library NAPT
#include <lwip/napt.h>
#include <lwip/dns.h>
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

namespace repeater {
    void connect(String ssid, String pass){
        File file = LittleFS.open("/ssid.txt", "w");
        if(file) { file.print(ssid); file.close(); }
        file = LittleFS.open("/pass.txt", "w");
        if(file) { file.print(pass); file.close(); }
        WiFi.mode(WIFI_AP_STA);
        WiFi.begin(ssid.c_str(), pass.c_str());
    }

    void run() {
        wifi::stopAP();
        WiFi.mode(WIFI_STA);
        EEPROM.write(400, 0);
        EEPROM.commit();
        
        // Langsung hajar login (simple version untuk bypass error)
        if(WiFi.status() != WL_CONNECTED) delay(1000);
        
        dhcps_set_dns(0, WiFi.dnsIP(0));
        WiFi.softAPConfig(IPAddress(172, 217, 28, 254), IPAddress(172, 217, 28, 254), IPAddress(255, 255, 255, 0));
        WiFi.softAP(ap_settings.ssid, ap_settings.password);
        
        if (ip_napt_init(NAPT, NAPT_PORT) == ERR_OK) {
            ip_napt_enable_no(SOFTAP_IF, 1);
            state = true;
        }
    }

    bool status() { return state; }
    void update_status(bool s) { state = s; }
}
