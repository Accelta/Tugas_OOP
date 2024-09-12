#include <iostream>
#include <string>

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
};

class Pelanggan {
private:
    int nilaiEmosi;
    int waktuTunggu;
public:
    Pelanggan() : nilaiEmosi(5), waktuTunggu(0) {}

    void kurangiEmosi() {
        if (nilaiEmosi > 1) {
            nilaiEmosi--;
        }
    }

    int getEmosi() {
        return nilaiEmosi;
    }

    void resetEmosi() {
        nilaiEmosi = 5;  // Reset emosi ke 5 (paling bahagia) setelah pesanan diantar
    }
};

class Pelayan {
public:
    void ambilPesanan(Meja& meja) {
        meja.ubahStatusPesanan("Di Dapur");
    }

    void kirimPesananKeDapur() {
        // Logika mengirim pesanan ke dapur
        std::cout << "Pesanan dikirim ke dapur." << std::endl;
    }

    void antarPesanan(Meja& meja, Pelanggan& pelanggan) {
        meja.ubahStatusPesanan("Sudah Disajikan");
        pelanggan.resetEmosi();
        std::cout << "Pesanan sudah diantar ke meja." << std::endl;
    }
};

class Dapur {
public:
    void selesaikanPesanan(Meja& meja) {
        std::cout << "Pesanan untuk meja siap." << std::endl;
    }
};

int main() {
    Meja meja1;
    Pelanggan pelanggan1;
    Pelayan pelayan1;
    Dapur dapur1;

    // Menampilkan status awal pesanan di meja
    meja1.tampilkanStatusPesanan();

    // Pelayan mengambil pesanan dan mengirim ke dapur
    pelayan1.ambilPesanan(meja1);
    pelayan1.kirimPesananKeDapur();
    meja1.tampilkanStatusPesanan();

    // Pesanan selesai di dapur
    dapur1.selesaikanPesanan(meja1);

    // Pelayan mengantarkan pesanan ke meja
    pelayan1.antarPesanan(meja1, pelanggan1);
    meja1.tampilkanStatusPesanan();

    // Menampilkan emosi pelanggan setelah pesanan diantar
    std::cout << "Emosi Pelanggan: " << pelanggan1.getEmosi() << std::endl;

    return 0;
}
