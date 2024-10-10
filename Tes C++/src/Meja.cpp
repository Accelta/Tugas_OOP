#include "meja.h"
#include <iostream>
#include <mutex>

using namespace std;

Meja::Meja() : statusPesanan("Belum Diambil"), isAvailable(true), piringKotor(false), adaPelanggan(false), pelanggan(nullptr) {}

void Meja::tampilkanStatusPesanan() {
    lock_guard<mutex> lock(mtx);
    cout << "Status Pesanan: " << statusPesanan << endl;
}

void Meja::ubahStatusPesanan(const string& status) {
    {
        lock_guard<mutex> lock(mtx);
        statusPesanan = status;
    }
    notify();
}

string Meja::getStatusPesanan() {
    lock_guard<mutex> lock(mtx);
    return statusPesanan;
}

bool Meja::getAvailableStatus() {
    lock_guard<mutex> lock(mtx);
    return isAvailable;
}

bool Meja::getPiringKotorStatus() {
    lock_guard<mutex> lock(mtx);
    return piringKotor;
}

bool Meja::adaPelangganDiMeja() {
    lock_guard<mutex> lock(mtx);
    return adaPelanggan;
}

void Meja::kosongkanMeja() {
    lock_guard<mutex> lock(mtx);
    isAvailable = true;
    piringKotor = false;
    adaPelanggan = false;
    pelanggan = nullptr;  // Kosongkan referensi pelanggan
    statusPesanan = "Belum Diambil";
    cout << "Meja sekarang kosong dan siap untuk pelanggan berikutnya.\n";
}

void Meja::isiMeja(Pelanggan* p) {
    lock_guard<mutex> lock(mtx);
    isAvailable = false;
    adaPelanggan = true;
    pelanggan = p;  // Set pelanggan di meja
}

Pelanggan* Meja::getPelanggan() {
    lock_guard<mutex> lock(mtx);
    return pelanggan;
}

void Meja::piringKotorMeja() {
    lock_guard<mutex> lock(mtx);
    piringKotor = true;
}

void Meja::bersihkanPiring() {
    lock_guard<mutex> lock(mtx);
    piringKotor = false;
    cout << "Piring kotor telah dibersihkan dari meja.\n";
}
