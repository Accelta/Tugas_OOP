#ifndef PELAYAN_H
#define PELAYAN_H

#include "Meja.h"
#include "Pelanggan.h"

class Pelayan {
public:
    void ambilPesanan(Meja& meja);
    void kirimPesananKeDapur();
    void antarPesanan(Meja& meja, Pelanggan& pelanggan);
};

#endif // PELAYAN_H
