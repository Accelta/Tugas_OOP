#ifndef DAPUR_H
#define DAPUR_H

#include "Meja.h"
#include <iostream>

class Dapur {
private:
    bool pesananSiap;

public:
    Dapur();
    void mulaiMemasak();
    bool isPesananSiap() const;
    void selesaiPesanan(Meja& meja);
};

#endif
