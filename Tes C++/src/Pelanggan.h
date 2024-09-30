#ifndef PELANGGAN_H
#define PELANGGAN_H

class Pelanggan {
private:
    int nilaiEmosi;
    int waktuTunggu;
public:
    Pelanggan();
    void kurangiEmosi();
    int getEmosi();
    void resetEmosi();
};

#endif // PELANGGAN_H
