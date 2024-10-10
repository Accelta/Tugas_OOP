#include "Pelayan.h"
#include <iostream>
#include <vector>

using namespace std;

Pelayan::Pelayan(const vector<Meja*>& mejaList) : mejaList(mejaList) {
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
        cout << "Meja kosong. Tidak ada pelanggan untuk diambil pesanannya.\n";
    } else if (meja.getStatusPesanan() == "Belum Diambil") {
        meja.ubahStatusPesanan("Di Dapur");
        cout << "Pelayan mengambil pesanan.\n";
    } else {
        cout << "Tidak ada pesanan yang dapat diambil atau sudah diambil.\n";
    }
}

void Pelayan::antarPesanan(Meja& meja, Pelanggan& pelanggan) {
    if (!meja.adaPelangganDiMeja()) {
        cout << "Meja kosong. Tidak ada pelanggan untuk diantar pesanan.\n";
    } else {
        string statusPesanan = meja.getStatusPesanan();

        if (statusPesanan == "Sudah Siap") {
            meja.ubahStatusPesanan("Sudah Disajikan");
            pelanggan.beriPesanan();   // Pelanggan menerima pesanan
            pelanggan.pergiDariMeja(); // Pelanggan pergi setelah menerima pesanan
            meja.piringKotorMeja();    // Meja sekarang memiliki piring kotor
            cout << "Pelayan mengantarkan pesanan ke meja.\n";
        } else {
           cout << "Pesanan belum siap untuk diantar.\n";
        }
    }
}

void Pelayan::bersihkanMeja(Meja& meja) {
    if (meja.getPiringKotorStatus()) {
        meja.bersihkanPiring();
        meja.kosongkanMeja(); // Setelah piring dibersihkan, meja kembali siap

        // Temukan indeks meja
        int mejaIndex = -1;
        for (size_t i = 0; i < mejaList.size(); ++i) {
            if (mejaList[i] == &meja) {
                mejaIndex = static_cast<int>(i);
                break;
            }
        }

        if (mejaIndex != -1) {
            cout << "Meja " << mejaIndex << " sekarang bersih dan siap untuk digunakan kembali.\n";
        } else {
            cout << "Meja tidak ditemukan dalam daftar.\n";
        }
    } else {
        cout << "Tidak ada piring kotor di meja.\n";
    }
}

void Pelayan::update() {
    for (Meja* meja : mejaList) {
        if (meja->getStatusPesanan() == "Sudah Disajikan") {
            cout << "Pesanan di meja sudah disajikan!\n";
        }
    }
}
