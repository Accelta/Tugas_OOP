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

// void Pelayan::antarPesanan(Meja& meja, Pelanggan& pelanggan) {
//     if (!meja.adaPelangganDiMeja()) {
//         std::cout << "Meja kosong. Tidak ada pelanggan untuk diantar pesanan.\n";
//     } else {
//         std::string statusPesanan = meja.getStatusPesanan();
//         if (statusPesanan == "Sudah Siap") {
//             meja.ubahStatusPesanan("Sudah Disajikan");
//             pelanggan.beriPesanan();
//             meja.piringKotorMeja();
//             std::cout << "Pelayan mengantarkan pesanan ke meja.\n";
//         } else {
//             std::cout << "Pesanan belum siap untuk diantar.\n";
//         }
//     }
// }
void Pelayan::antarPesanan(Meja& meja, Pelanggan& pelanggan) {
    if (!meja.adaPelangganDiMeja()) {
        std::cout << "Meja kosong. Tidak ada pelanggan untuk diantar pesanan.\n";
    } else {
        std::string statusPesanan = meja.getStatusPesanan();

        if (statusPesanan == "Sudah Siap") {
            meja.ubahStatusPesanan("Sudah Disajikan");
            pelanggan.beriPesanan();
            pelanggan.pergiDariMeja();  // Pelanggan menerima pesanan dan pergi
            meja.piringKotorMeja();  // Tandai meja sebagai kotor
           std::cout << "Pelayan mengantarkan pesanan ke meja.\n";
        } else {
            std::cout << "Pesanan belum siap untuk diantar.\n";
        }
    }
}

// void Pelayan::bersihkanMeja(Meja& meja) {
//     if (meja.getPiringKotorStatus()) {
//         meja.bersihkanPiring();
//     } else {
//         std::cout << "Tidak ada piring kotor di meja.\n";
//     }
// }
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
            std::cout << "Meja " << mejaIndex << " sekarang bersih dan siap untuk digunakan kembali.\n";
        } else {
            std::cout << "Meja tidak ditemukan dalam daftar.\n";
        }
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
