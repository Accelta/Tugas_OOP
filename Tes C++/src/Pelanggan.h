#ifndef PELANGGAN_H
#define PELANGGAN_H

#include <iostream>

class Pelanggan {
private:
    int nilaiEmosi;

public:
    Pelanggan();
    void kurangiEmosi();
    int getEmosi();
    void resetEmosi();
    void tampilkanEmosi();
};

#endif
