#ifndef MEJA_H
#define MEJA_H

#include <string>
#include <iostream>

class Meja {
private:
    std::string statusPesanan;
public:
    Meja();
    void tampilkanStatusPesanan();
    void ubahStatusPesanan(std::string status);
    std::string getStatusPesanan();
};

#endif // MEJA_H

