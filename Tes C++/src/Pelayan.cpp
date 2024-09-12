#include "Pelayan.h"

void Pelayan::ambilPesanan(Meja& meja) {
    meja.ubahStatusPesanan("Di Dapur");
    std::cout << "Pesanan diambil oleh pelayan.\n";
}

void Pelayan::kirimPesananKeDapur() {
    std::cout << "Pesanan dikirim ke dapur." << std::endl;
}

void Pelayan::antarPesanan(Meja& meja, Pelanggan& pelanggan) {
    if (meja.getStatusPesanan() == "Siap Diantar") {
        meja.ubahStatusPesanan("Sudah Disajikan");
        pelanggan.resetEmosi();
        std::cout << "Pesanan sudah diantar ke meja." << std::endl;
    } else {
        std::cout << "Pesanan belum siap untuk diantar.\n";
    }
}
