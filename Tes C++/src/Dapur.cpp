#include "Dapur.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void Dapur::selesaikanPesanan(Meja& meja) {
    if (meja.getStatusPesanan() == "Di Dapur") {
        this_thread::sleep_for(chrono::seconds(2));
        meja.ubahStatusPesanan("Sudah Siap");
        cout << "Pesanan untuk meja sudah siap.\n";
    }
}
