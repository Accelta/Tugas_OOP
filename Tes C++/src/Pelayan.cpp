#include "Pelayan.h"
#include <iostream>

Pelayan::Pelayan(const std::vector<Meja*>& mejaList) : mejaList(mejaList) {
    for (Meja* meja : mejaList) {
        meja->addObserver(this);
    }
}

Pelayan::~Pelayan() {
    for (Meja* meja : mejaList) {
        meja->removeObserver(this);
    }
}

void Pelayan::ambilPesanan(Meja& meja) {
    if (!meja.adaPelangganDiMeja()) {
        std::cout << "Meja kosong. Tidak ada pelanggan untuk diambil pesanannya.\n";
    } else if (meja.getStatusPesanan() == "Belum Diambil") {
        meja.ubahStatusPesanan("Di Dapur");
        std::cout << "Pelayan mengambil pesanan.\n";
    } else {
        std::cout << "Tidak ada pesanan yang dapat diambil atau sudah diambil.\n";
    }
}

void Pelayan::antarPesanan(Meja& meja, Pelanggan& pelanggan) {
    if (!meja.adaPelangganDiMeja()) {
        std::cout << "Meja kosong. Tidak ada pelanggan untuk diantar pesanan.\n";
    } else {
        std::string statusPesanan = meja.getStatusPesanan();

        if (statusPesanan == "Sudah Siap") {
            meja.ubahStatusPesanan("Sudah Disajikan");
            pelanggan.beriPesanan();
            meja.piringKotorMeja();
            std::cout << "Pelayan mengantarkan pesanan ke meja.\n";
        } else {
            std::cout << "Pesanan belum siap untuk diantar.\n";
        }
    }
}

void Pelayan::bersihkanMeja(Meja& meja) {
    if (meja.getPiringKotorStatus()) {
        meja.bersihkanPiring();
    } else {
        std::cout << "Tidak ada piring kotor di meja.\n";
    }
}

void Pelayan::update() {
    for (Meja* meja : mejaList) {
        if (meja->getStatusPesanan() == "Sudah Disajikan") {
            std::cout << "Pesanan di meja sudah disajikan!\n";
        }
    }
}
