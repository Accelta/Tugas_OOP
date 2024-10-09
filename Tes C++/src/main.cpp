
#include <iostream>
#include <queue>
#include <memory>
#include "Meja.h"
#include "Pelanggan.h"
#include "Pelayan.h"
#include "Dapur.h"

void tampilkanMenu(std::queue<std::unique_ptr<Pelanggan>>& antrianPelanggan, std::vector<std::unique_ptr<Meja>>& daftarMeja, std::vector<Pelayan>& pelayan, Dapur& dapur) {
    int pilihan;

    do {
        std::cout << "Menu:\n";
        std::cout << "Pelanggan dalam antrian : "<< antrianPelanggan.size() <<"\n";
        std::cout << "1. Tempatkan pelanggan di meja\n";
        std::cout << "2. Ambil pesanan dari meja\n";
        std::cout << "3. Antar pesanan ke meja\n";
        std::cout << "4. Bersihkan meja\n";
        std::cout << "5. Keluar\n";
        std::cout << "Pilih opsi: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1: {
                if (!antrianPelanggan.empty()) {
                    for (auto& meja : daftarMeja) {
                        if (meja->getAvailableStatus()) {
                            meja->isiMeja();
                            antrianPelanggan.pop();
                            std::cout << "Pelanggan ditempatkan di meja.\n";
                            break;
                        }
                    }
                } else {
                    std::cout << "Tidak ada pelanggan dalam antrian.\n";
                }
                break;
            }
            case 2: {
                int mejaIndex;
                std::cout << "Pilih meja untuk mengambil pesanan (0-2): ";
                std::cin >> mejaIndex;

                if (mejaIndex >= 0 && mejaIndex < daftarMeja.size()) {
                    pelayan[0].ambilPesanan(*daftarMeja[mejaIndex]);
                } else {
                    std::cout << "Meja tidak valid.\n";
                }
                break;
            }
            case 3: {
                int mejaIndex;
                std::cout << "Pilih meja untuk mengantar pesanan (0-2): ";
                std::cin >> mejaIndex;

                if (mejaIndex >= 0 && mejaIndex < daftarMeja.size()) {
                    pelayan[0].antarPesanan(*daftarMeja[mejaIndex], *antrianPelanggan.front());
                } else {
                    std::cout << "Meja tidak valid.\n";
                }
                break;
            }
            case 4: {
                int mejaIndex;
                std::cout << "Pilih meja untuk dibersihkan (0-2): ";
                std::cin >> mejaIndex;

                if (mejaIndex >= 0 && mejaIndex < daftarMeja.size()) {
                    pelayan[0].bersihkanMeja(*daftarMeja[mejaIndex]);
                } else {
                    std::cout << "Meja tidak valid.\n";
                }
                break;
            }
            case 5:
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 5);
}

int main() {
    std::queue<std::unique_ptr<Pelanggan>> antrianPelanggan;
    for (int i = 0; i < 3; ++i) {
        antrianPelanggan.push(std::make_unique<Pelanggan>());
    }

    std::vector<std::unique_ptr<Meja>> daftarMeja;
    for (int i = 0; i < 3; ++i) {
        daftarMeja.push_back(std::make_unique<Meja>());
    }

    Dapur dapur1;
    std::vector<Pelayan> pelayan = { Pelayan({daftarMeja[0].get(), daftarMeja[1].get(), daftarMeja[2].get()}) };

    tampilkanMenu(antrianPelanggan, daftarMeja, pelayan, dapur1);

    return 0;
}