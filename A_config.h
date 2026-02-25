/* This software is licensed under the MIT License: https://github.com/spacehuhntech/esp8266_deauther */

#pragma once

// =========================================
// 1. CORE SETTINGS (Anti-Error)
// =========================================
#define DEAUTHER_VERSION "2.6.1"
#define DEAUTHER_VERSION_MAJOR 2
#define DEAUTHER_VERSION_MINOR 6
#define DEAUTHER_VERSION_REVISION 1

#define EEPROM_SIZE 4095
#define BOOT_COUNTER_ADDR 1
#define SETTINGS_ADDR 100

// =========================================
// 2. HARDWARE SELECTION (NodeMCU)
// =========================================
#define NODEMCU // Mengaktifkan konfigurasi NodeMCU

#define STROBE 2
#define NYALA HIGH
#define MATI LOW

// =========================================
// 3. NODEMCU SPECIFIC CONFIG
// =========================================
#ifdef NODEMCU
  // LED
  #define USE_LED true
  #define LED_NEOPIXEL_GRB
  #define LED_NUM 1
  #define LED_NEOPIXEL_PIN 15 // Pin D8 di NodeMCU
  #define LED_MODE_BRIGHTNESS 10
  
  // DISPLAY
  #define USE_DISPLAY true
  #define FLIP_DIPLAY true
  #define SH1106_I2C          // Pakai SH1106 (OLED 1.3 inch)
  #define I2C_ADDR 0x3C
  #define I2C_SDA 4           // Pin D2
  #define I2C_SCL 5           // Pin D1
  #define DISPLAY_TEXT "WifiX v1.5"
  #define INTRO_STR "WifiX v1.5"

  // BUTTONS
  #define BUTTON_UP 14        // Pin D5
  #define BUTTON_DOWN 12      // Pin D6
  #define BUTTON_A 2          // Pin D4
  #define BUTTON_B 0          // Pin D3
  #define RESET_BUTTON 0      // Pin Flash/D3
#endif

// =========================================
// 4. NETWORK & WEB
// =========================================
#define AP_SSID "#WifiX.1.5#"
#define AP_PASSWD "deauther"
#define AP_HIDDEN false
#define AP_IP_ADDR { 192, 168, 4, 1 }

#define WEB_ENABLED true
#define WEB_IP_ADDR (192, 168, 4, 1)
#define WEB_URL "deauth.me"
#define WEB_CAPTIVE_PORTAL false
#define WEB_USE_SPIFFS false
#define DEFAULT_LANG "en"

// =========================================
// 5. ATTACK & SYSTEM FEATURES
// =========================================
#define ATTACK_ALL_CH false
#define RANDOM_TX false
#define ATTACK_TIMEOUT 0
#define DEAUTHS_PER_TARGET 25
#define DEAUTH_REASON 1
#define PROBE_FRAMES_PER_SSID 1
#define CH_TIME 200
#define MIN_DEAUTH_FRAMES 3
#define CLI_ENABLED true
#define CLI_ECHO true
#define DISPLAY_TIMEOUT 600

// =========================================
// 6. DEBUGGING
// =========================================
#define ENABLE_DEBUG
#define DEBUG_PORT Serial
#define DEBUG_BAUD 115200

// =========================================
// 7. LED COLORS
// =========================================
#define LED_MODE_OFF 0, 0, 0
#define LED_MODE_SCAN 0, 0, 255
#define LED_MODE_ATTACK 255, 0, 0
#define LED_MODE_IDLE 0, 255, 0

#if LED_MODE_BRIGHTNESS == 0
#error LED_MODE_BRIGHTNESS must not be zero!
#endif
