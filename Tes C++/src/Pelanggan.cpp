// #include "Pelanggan.h"

// Pelanggan::Pelanggan() : nilaiEmosi(5) {}

// void Pelanggan::kurangiEmosi() {
//     if (nilaiEmosi > 1) {
//         nilaiEmosi--;
//     }
// }

// int Pelanggan::getEmosi() {
//     return nilaiEmosi;
// }

// void Pelanggan::resetEmosi() {
//     nilaiEmosi = 5;
// }

// void Pelanggan::tampilkanEmosi() {
//     std::cout << "Emosi Pelanggan: " << nilaiEmosi << std::endl;
// }
#include "Pelanggan.h"

Pelanggan::Pelanggan() : nilaiEmosi(5) {}

void Pelanggan::kurangiEmosi() {
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
    if (nilaiEmosi > 1) {
        nilaiEmosi--;
    }
}

int Pelanggan::getEmosi() {
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
    return nilaiEmosi;
}

void Pelanggan::resetEmosi() {
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
    nilaiEmosi = 5;
}

void Pelanggan::tampilkanEmosi() {
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
    std::cout << "Emosi Pelanggan: " << nilaiEmosi << std::endl;
}
