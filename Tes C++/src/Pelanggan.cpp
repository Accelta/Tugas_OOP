#include "Pelanggan.h"

Pelanggan::Pelanggan() : nilaiEmosi(5), waktuTunggu(0) {}

void Pelanggan::kurangiEmosi() {
    if (nilaiEmosi > 1) {
        nilaiEmosi--;
    }
}

int Pelanggan::getEmosi() {
    return nilaiEmosi;
}

void Pelanggan::resetEmosi() {
    nilaiEmosi = 5;  // Reset emosi ke 5 (paling bahagia) setelah pesanan diantar
}
