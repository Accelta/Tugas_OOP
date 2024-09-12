#include "Meja.h"

Meja::Meja() : statusPesanan("Belum Diambil") {}

void Meja::tampilkanStatusPesanan() {
    std::cout << "Status Pesanan: " << statusPesanan << std::endl;
}

void Meja::ubahStatusPesanan(std::string status) {
    statusPesanan = status;
}

std::string Meja::getStatusPesanan() {
    return statusPesanan;
}
