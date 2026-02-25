#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

// JANGAN naruh #include di bawah extern "C"
#ifdef __cplusplus
extern "C" {
#endif

void debug_setup();

#ifdef __cplusplus
}
#endif

#define debug_init() 
#define debug(...) 
#define debugln(...) 
#define debugf(...) 
#define debugF(...) 
#define debuglnF(...) 
#define debug_available() 0
#define debug_read() 0
#define debug_peek() 0

#endif
