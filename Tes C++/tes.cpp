// #include <iostream>
// #include <string>
// using namespace std;

// class Meja {
// private:
//     std::string statusPesanan;
// public:
//     Meja() : statusPesanan("Belum Diambil") {}

//     void tampilkanStatusPesanan() {
//         std::cout << "Status Pesanan: " << statusPesanan << std::endl;
//     }

//     void ubahStatusPesanan(std::string status) {
//         statusPesanan = status;
//     }
// };

// class Pelanggan {
// private:
//     int nilaiEmosi;
//     int waktuTunggu;
// public:
//     Pelanggan() : nilaiEmosi(5), waktuTunggu(0) {}

//     void kurangiEmosi() {
//         if (nilaiEmosi > 1) {
//             nilaiEmosi--;
//         }
//     }

//     int getEmosi() {
//         return nilaiEmosi;
//     }

//     void resetEmosi() {
//         nilaiEmosi = 5;  // Reset emosi ke 5 (paling bahagia) setelah pesanan diantar
//     }
// };

// class Pelayan {
// public:
//     void ambilPesanan(Meja& meja) {
//         meja.ubahStatusPesanan("Di Dapur");
//     }

//     void kirimPesananKeDapur() {
//         // Logika mengirim pesanan ke dapur
//         std::cout << "Pesanan dikirim ke dapur." << std::endl;
//     }

//     void antarPesanan(Meja& meja, Pelanggan& pelanggan) {
//         meja.ubahStatusPesanan("Sudah Disajikan");
//         pelanggan.resetEmosi();
//         std::cout << "Pesanan sudah diantar ke meja." << std::endl;
//     }
// };

// class Dapur {
// public:
//     void selesaikanPesanan(Meja& meja) {
//         std::cout << "Pesanan untuk meja siap." << std::endl;
//     }
// };

// int main() {
//     Meja meja1;
//     Pelanggan pelanggan1;
//     Pelayan pelayan1;
//     Dapur dapur1;

//     // Menampilkan status awal pesanan di meja
//     meja1.tampilkanStatusPesanan();

//     // Pelayan mengambil pesanan dan mengirim ke dapur
//     pelayan1.ambilPesanan(meja1);
//     pelayan1.kirimPesananKeDapur();
//     meja1.tampilkanStatusPesanan();

//     // Pesanan selesai di dapur
//     dapur1.selesaikanPesanan(meja1);

//     // Pelayan mengantarkan pesanan ke meja
//     pelayan1.antarPesanan(meja1, pelanggan1);
//     meja1.tampilkanStatusPesanan();

//     // Menampilkan emosi pelanggan setelah pesanan diantar
//     std::cout << "Emosi Pelanggan: " << pelanggan1.getEmosi() << std::endl;

//     return 0;
// }

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class Meja {
private:
    std::string statusPesanan;
public:
    Meja() : statusPesanan("Belum Diambil") {}

    void tampilkanStatusPesanan() {
        std::cout << "Status Pesanan: " << statusPesanan << std::endl;
    }

    void ubahStatusPesanan(std::string status) {
        statusPesanan = status;
    }

    std::string getStatusPesanan() {
        return statusPesanan;
    }
};

class Pelanggan {
private:
    int nilaiEmosi;
public:
    Pelanggan() : nilaiEmosi(5) {}

    void kurangiEmosi() {
        if (nilaiEmosi > 1) {
            nilaiEmosi--;
        }
    }

    int getEmosi() {
        return nilaiEmosi;
    }

    void resetEmosi() {
        nilaiEmosi = 5;  // Reset emosi ke 5 setelah pesanan diantar
    }

    void tampilkanEmosi() {
        std::cout << "Emosi Pelanggan: " << nilaiEmosi << std::endl;
    }
};

class Pelayan {
public:
    void ambilPesanan(Meja& meja) {
        meja.ubahStatusPesanan("Di Dapur");
        std::cout << "Pesanan diambil oleh pelayan.\n";
    }

    void kirimPesananKeDapur() {
        std::cout << "Pesanan dikirim ke dapur." << std::endl;
    }

    void antarPesanan(Meja& meja, Pelanggan& pelanggan) {
        if (meja.getStatusPesanan() == "Siap Diantar") {
            meja.ubahStatusPesanan("Sudah Disajikan");
            pelanggan.resetEmosi();
            std::cout << "Pesanan sudah diantar ke meja." << std::endl;
        } else {
            std::cout << "Pesanan belum siap untuk diantar.\n";
        }
    }
};

class Dapur {
private:
    bool pesananSiap;
public:
    Dapur() : pesananSiap(false) {}

    void mulaiMemasak() {
        std::cout << "Memasak pesanan...\n";
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Simulate cooking time
        pesananSiap = true;
        std::cout << "Pesanan siap untuk diantar.\n";
    }

    bool isPesananSiap() const {
        return pesananSiap;
    }

    void selesaiPesanan(Meja& meja) {
        if (pesananSiap) {
            meja.ubahStatusPesanan("Siap Diantar");
            std::cout << "Pesanan untuk meja sudah siap.\n";
        }
    }
};

// Simulate decreasing customer emotion over time
void emosiPelangganTurun(Pelanggan& pelanggan) {
    while (pelanggan.getEmosi() > 1) {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Emotion decreases every 2 seconds
        pelanggan.kurangiEmosi();
        pelanggan.tampilkanEmosi();
    }
}

int main() {
    Meja meja1;
    Pelanggan pelanggan1;
    Pelayan pelayan1;
    Dapur dapur1;

    // Start a thread to simulate customer's emotion decreasing over time
    std::thread threadEmosi(emosiPelangganTurun, std::ref(pelanggan1));

    // Menampilkan status awal pesanan di meja
    meja1.tampilkanStatusPesanan();

    // Pelayan mengambil pesanan dan mengirim ke dapur
    pelayan1.ambilPesanan(meja1);
    pelayan1.kirimPesananKeDapur();
    meja1.tampilkanStatusPesanan();

    // Dapur memulai memasak pesanan
    dapur1.mulaiMemasak();
    dapur1.selesaiPesanan(meja1);

    // Pelayan mengantarkan pesanan ke meja
    pelayan1.antarPesanan(meja1, pelanggan1);
    meja1.tampilkanStatusPesanan();

    // Wait for the emotion thread to finish
    threadEmosi.join();

    return 0;
}
