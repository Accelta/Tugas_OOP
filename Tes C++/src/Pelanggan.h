#ifndef PELANGGAN_H
#define PELANGGAN_H

#include <mutex>

using namespace std;

class Pelanggan {
private:
    bool sudahDiberiPesanan;
    mutable mutex mtx;

public:
    Pelanggan();
    bool sudahMendapatPesanan() const;
    void beriPesanan();
    void pergiDariMeja();
};

#endif // PELANGGAN_H
