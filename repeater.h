#ifndef REPEATER_H
#define REPEATER_H

#include <Arduino.h>

// Pastikan namespace ini murni C++ agar tidak kena error "template with C linkage"
namespace repeater {
    // Dipanggil untuk menyimpan SSID dan Password target yang akan diperkuat (repeat)
    void connect(String ssid, String pass);
    
    // Fungsi eksekusi utama untuk mengaktifkan mode NAPT
    void run();
    
    // Fungsi untuk mengecek apakah mode repeater sedang berjalan
    bool status();
    
    // Fungsi untuk memperbarui variabel status (true/false)
    void update_status(bool s);
}

#endif
