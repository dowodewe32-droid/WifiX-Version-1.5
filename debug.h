#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

// JANGAN pakai extern "C" karena akan menyebabkan error "template with C linkage"
#define ENABLE_DEBUG
#define DEBUG_PORT Serial

#ifdef ENABLE_DEBUG
  #define debug(...) DEBUG_PORT.print(__VA_ARGS__)
  #define debugln(...) DEBUG_PORT.println(__VA_ARGS__)
  #define debugF(...) DEBUG_PORT.print(__VA_ARGS__)
  #define debuglnF(...) DEBUG_PORT.println(__VA_ARGS__)
#else
  #define debug(...)
  #define debugln(...)
  #define debugF(...)
  #define debuglnF(...)
#endif

#endif
