#include "Dapur.h"
#include <iostream>
#include <thread>
#include <chrono>

void Dapur::selesaikanPesanan(Meja& meja) {
    if (meja.getStatusPesanan() == "Di Dapur") {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        meja.ubahStatusPesanan("Sudah Siap");
        std::cout << "Pesanan untuk meja sudah siap.\n";
    }
}
