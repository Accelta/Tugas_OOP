#include "Dapur.h"
#include <thread>
#include <chrono>

Dapur::Dapur() : pesananSiap(false) {}

void Dapur::mulaiMemasak() {
    std::cout << "Memasak pesanan...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3)); // Simulate cooking time
    pesananSiap = true;
    std::cout << "Pesanan siap untuk diantar.\n";
}

bool Dapur::isPesananSiap() const {
    return pesananSiap;
}

void Dapur::selesaiPesanan(Meja& meja) {
    if (pesananSiap) {
        meja.ubahStatusPesanan("Siap Diantar");
        std::cout << "Pesanan untuk meja sudah siap.\n";
    }
}
