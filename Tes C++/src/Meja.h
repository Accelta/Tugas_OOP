#ifndef MEJA_H
#define MEJA_H

#include <string>

class Meja {
private:
    std::string statusPesanan;
public:
    Meja();
    void tampilkanStatusPesanan();
    void ubahStatusPesanan(std::string status);
};

#endif // MEJA_H
