#ifndef PELANGGAN_H
#define PELANGGAN_H

#include <mutex>

class Pelanggan {
private:
    bool sudahDiberiPesanan;
    mutable std::mutex mtx;

public:
    Pelanggan();
    bool sudahMendapatPesanan() const;
    void beriPesanan();
    void pergiDariMeja();
};

#endif
