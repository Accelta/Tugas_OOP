#ifndef MEJA_H
#define MEJA_H

#include <iostream>
#include <string>
#include <mutex>
#include "Observer.h"

class Meja : public Subject {
private:
    std::string statusPesanan;
    bool isAvailable;
    bool piringKotor;
    bool adaPelanggan;
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
    void isiMeja();
    void piringKotorMeja();
    void bersihkanPiring();
};

#endif
