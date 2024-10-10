#include "Pelanggan.h"
#include <iostream>
#include <mutex>

using namespace std;

Pelanggan::Pelanggan() : sudahDiberiPesanan(false) {}

bool Pelanggan::sudahMendapatPesanan() const {
    lock_guard<mutex> lock(mtx);
    return sudahDiberiPesanan;
}

void Pelanggan::beriPesanan() {
    lock_guard<mutex> lock(mtx);
    sudahDiberiPesanan = true;
}

void Pelanggan::pergiDariMeja() {
    cout << "Pelanggan sudah menerima pesanan dan pergi.\n";
}
