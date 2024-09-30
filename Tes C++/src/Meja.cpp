#include "Meja.h"

Meja::Meja() : statusPesanan("Belum Diambil") {}

void Meja::tampilkanStatusPesanan() {
    std::cout << "Debug: Checking statusPesanan pointer..." << std::endl;
    
    // Make sure the string is valid before accessing it
    if (statusPesanan.empty()) {
        std::cerr << "Error: statusPesanan is empty or uninitialized." << std::endl;
        return;
    }
    
    std::cout << "Status Pesanan: " << statusPesanan << std::endl;
}

void Meja::ubahStatusPesanan(std::string status) {
    statusPesanan = status;
}

std::string Meja::getStatusPesanan() {
    return statusPesanan;
}
