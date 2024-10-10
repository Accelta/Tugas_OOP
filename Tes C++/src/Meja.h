#ifndef MEJA_H
#define MEJA_H

#include <iostream>
#include <string>
#include <mutex>
#include "observer.h"
#include "pelanggan.h"
#include "subject.h"

class Meja : public Subject {
private:
    std::string statusPesanan;
    bool isAvailable;
    bool piringKotor;
    bool adaPelanggan;
    Pelanggan* pelanggan;  // Tambahkan referensi ke Pelanggan
    std::mutex mtx;

public:
    Meja();
    void tampilkanStatusPesanan();
    void ubahStatusPesanan(const std::string& status);
    std::string getStatusPesanan();
    bool getAvailableStatus();
    bool getPiringKotorStatus();
    bool adaPelangganDiMeja();
    void kosongkanMeja();
    void isiMeja(Pelanggan* p);  // Metode untuk menempatkan pelanggan di meja
    Pelanggan* getPelanggan();   // Metode untuk mendapatkan pelanggan di meja
    void piringKotorMeja();
    void bersihkanPiring();
};

#endif
