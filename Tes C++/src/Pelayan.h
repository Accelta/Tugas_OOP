#ifndef PELAYAN_H
#define PELAYAN_H

#include <vector>
#include "Meja.h"
#include "Pelanggan.h"
#include "Observer.h"

class Pelayan : public Observer {
public:
    std::vector<Meja*> mejaList;
public:
    Pelayan(const std::vector<Meja*>& mejaList);
    ~Pelayan();
    void ambilPesanan(Meja& meja);
    void antarPesanan(Meja& meja, Pelanggan& pelanggan);
    void bersihkanMeja(Meja& meja);
    void update() override;
};

#endif
