#ifndef MEJA_H
#define MEJA_H

#include <iostream>
#include <string>
#include <mutex>
#include "observer.h"
#include "pelanggan.h"
#include "subject.h"    

using namespace std;

class Meja : public Subject {
private:
    string statusPesanan;
    bool isAvailable;
    bool piringKotor;
    bool adaPelanggan;
    Pelanggan* pelanggan;  // Tambahkan referensi ke Pelanggan
    mutex mtx;

public:
    Meja();
    void tampilkanStatusPesanan();
    void ubahStatusPesanan(const string& status);
    string getStatusPesanan();
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
