#include "Meja.h"
#include <iostream>

Meja::Meja() : statusPesanan("Belum Diambil") {}

void Meja::tampilkanStatusPesanan() {
    std::cout << "Status Pesanan: " << statusPesanan << std::endl;
}

void Meja::ubahStatusPesanan(std::string status) {
    statusPesanan = status;
}
