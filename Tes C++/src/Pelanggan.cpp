#include "Pelanggan.h"

Pelanggan::Pelanggan() : nilaiEmosi(5) {}

void Pelanggan::kurangiEmosi() {
    if (nilaiEmosi > 1) {
        nilaiEmosi--;
    }
}

int Pelanggan::getEmosi() {
    return nilaiEmosi;
}

void Pelanggan::resetEmosi() {
    nilaiEmosi = 5;
}

void Pelanggan::tampilkanEmosi() {
    std::cout << "Emosi Pelanggan: " << nilaiEmosi << std::endl;
}
