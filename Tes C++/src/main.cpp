#include "Meja.h"
#include "Pelanggan.h"
#include "Pelayan.h"
#include "Dapur.h"
#include <iostream>

int main() {
    Meja meja1;
    Pelanggan pelanggan1;
    Pelayan pelayan1;
    Dapur dapur1;

    // Menampilkan status awal pesanan di meja
    meja1.tampilkanStatusPesanan();

    // Pelayan mengambil pesanan dan mengirim ke dapur
    pelayan1.ambilPesanan(meja1);
    pelayan1.kirimPesananKeDapur();
    meja1.tampilkanStatusPesanan();

    // Pesanan selesai di dapur
    dapur1.selesaikanPesanan(meja1);

    // Pelayan mengantarkan pesanan ke meja
    pelayan1.antarPesanan(meja1, pelanggan1);
    meja1.tampilkanStatusPesanan();

    // Menampilkan emosi pelanggan setelah pesanan diantar
    std::cout << "Emosi Pelanggan: " << pelanggan1.getEmosi() << std::endl;

    return 0;
}
