#include "Pelanggan.h"
#include <iostream>

Pelanggan::Pelanggan() : sudahDiberiPesanan(false) {}

bool Pelanggan::sudahMendapatPesanan() const {
    std::lock_guard<std::mutex> lock(mtx);
    return sudahDiberiPesanan;
}

void Pelanggan::beriPesanan() {
    std::lock_guard<std::mutex> lock(mtx);
    sudahDiberiPesanan = true;
}

void Pelanggan::pergiDariMeja() {
    std::cout << "Pelanggan sudah menerima pesanan dan pergi.\n";
}
