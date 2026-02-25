#pragma once

// Hardware
#define NODEMCU
#define LED_NEOPIXEL_GRB
#define LED_NUM 1
#define LED_NEOPIXEL_PIN 15 // D8
#define LED_MODE_BRIGHTNESS 10
#define USE_LED true

// Display I2C
#define USE_DISPLAY true
#define SH1106_I2C
#define I2C_ADDR 0x3C
#define I2C_SDA 4
#define I2C_SCL 5

// Buttons
#define BUTTON_UP 14
#define BUTTON_DOWN 12
#define BUTTON_A 2
#define BUTTON_B 0
#define RESET_BUTTON 0

// System & Attack FIX
#define BOOT_COUNTER_ADDR 1
#define SETTINGS_ADDR 100
#define PROBE_FRAMES_PER_SSID 1
#define MIN_DEAUTH_FRAMES 3
#define CLI_ECHO true
#define DEAUTHER_VERSION "2.6.1"
