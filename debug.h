#ifndef DEBUG_H
#define DEBUG_H

// 1. PINDAHKAN INCLUDE KE LUAR DARI EXTERN "C"
#include "config.h"
#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif
    // Hanya fungsi C murni yang boleh di sini (jika ada)
#ifdef __cplusplus
}
#endif

// 2. DEFINE MACRO DEBUG DI LUAR EXTERN "C" KARENA PAKAI C++ (Serial)
#ifdef ENABLE_DEBUG
    #define debugF(...) DEBUG_PORT.print(__VA_ARGS__)
    #define debuglnF(...) DEBUG_PORT.println(__VA_ARGS__)
#else
    #define debugF(...)
    #define debuglnF(...)
#endif

#endif
