#ifndef PELAYAN_H
#define PELAYAN_H

#include "Observer.h"
#include "Meja.h"
#include "Pelanggan.h"
#include <vector>

using namespace std;

class Pelayan : public Observer {
public:
    vector<Meja*> mejaList;

    Pelayan(const vector<Meja*>& mejaList);
    ~Pelayan();

    void ambilPesanan(Meja& meja);
    void antarPesanan(Meja& meja, Pelanggan& pelanggan);
    void bersihkanMeja(Meja& meja);
    void update() override;
};

#endif // PELAYAN_H
