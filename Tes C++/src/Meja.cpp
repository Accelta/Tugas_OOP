#include "Meja.h"

Meja::Meja() : statusPesanan("Belum Diambil"), isAvailable(true), piringKotor(false), adaPelanggan(false) {}

void Meja::tampilkanStatusPesanan() {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Status Pesanan: " << statusPesanan << std::endl;
}

void Meja::ubahStatusPesanan(const std::string& status) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        statusPesanan = status;
    }
    notify();
}

std::string Meja::getStatusPesanan() {
    std::lock_guard<std::mutex> lock(mtx);
    return statusPesanan;
}

bool Meja::getAvailableStatus() {
    std::lock_guard<std::mutex> lock(mtx);
    return isAvailable;
}

bool Meja::getPiringKotorStatus() {
    std::lock_guard<std::mutex> lock(mtx);
    return piringKotor;
}

bool Meja::adaPelangganDiMeja() {
    std::lock_guard<std::mutex> lock(mtx);
    return adaPelanggan;
}

void Meja::kosongkanMeja() {
    std::lock_guard<std::mutex> lock(mtx);
    isAvailable = true;
    piringKotor = false;
    adaPelanggan = false;
    statusPesanan = "Belum Diambil";
    std::cout << "Meja sekarang kosong dan siap untuk pelanggan berikutnya.\n";
}

void Meja::isiMeja() {
    std::lock_guard<std::mutex> lock(mtx);
    isAvailable = false;
    adaPelanggan = true;
}

void Meja::piringKotorMeja() {
    std::lock_guard<std::mutex> lock(mtx);
    piringKotor = true;
}

void Meja::bersihkanPiring() {
    std::lock_guard<std::mutex> lock(mtx);
    piringKotor = false;
    std::cout << "Piring kotor telah dibersihkan dari meja.\n";
}
