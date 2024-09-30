// #ifndef PELANGGAN_H
// #define PELANGGAN_H

// #include <iostream>

// class Pelanggan {
// private:
//     int nilaiEmosi;

// public:
//     Pelanggan();
//     void kurangiEmosi();
//     int getEmosi();
//     void resetEmosi();
//     void tampilkanEmosi();
// };

// #endif
#ifndef PELANGGAN_H
#define PELANGGAN_H

#include <iostream>
#include <mutex>

class Pelanggan {
private:
    int nilaiEmosi;
    std::mutex mtx; // Mutex for thread safety

public:
    Pelanggan();
    void kurangiEmosi();
    int getEmosi();
    void resetEmosi();
    void tampilkanEmosi();
};

#endif
