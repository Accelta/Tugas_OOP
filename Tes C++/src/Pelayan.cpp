#include "Pelayan.h"
#include <iostream>

void Pelayan::ambilPesanan(Meja& meja) {
    meja.ubahStatusPesanan("Di Dapur");
}

void Pelayan::kirimPesananKeDapur() {
    std::cout << "Pesanan dikirim ke dapur." << std::endl;
}

void Pelayan::antarPesanan(Meja& meja, Pelanggan& pelanggan) {
    meja.ubahStatusPesanan("Sudah Disajikan");
    pelanggan.resetEmosi();
    std::cout << "Pesanan sudah diantar ke meja." << std::endl;
}
