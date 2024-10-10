
// #include <iostream>
// #include <string>
// #include <thread>
// #include <chrono>
// #include <vector>
// #include <list>
// #include <mutex>
// #include <queue>
// #include <limits>
// #include <memory>

// using namespace std;

// class Observer {
// public:
//     virtual void update() = 0;
// };

// class Subject {
// private:
//     list<Observer*> observers;
//     mutex mtx;
// public:
//     void addObserver(Observer* observer) {
//         lock_guard<mutex> lock(mtx);
//         observers.push_back(observer);
//     }

//     void removeObserver(Observer* observer) {
//         lock_guard<mutex> lock(mtx);
//         observers.remove(observer);
//     }

//     void notify() {
//         lock_guard<mutex> lock(mtx);
//         for (Observer* observer : observers) {
//             observer->update();
//         }
//     }
// };

// class Meja : public Subject {
// private:
//     string statusPesanan;
//     bool isAvailable;
//     bool piringKotor;
//     mutex mtx;

// public:
//     Meja() : statusPesanan("Belum Diambil"), isAvailable(true), piringKotor(false) {}

//     void tampilkanStatusPesanan() {
//         lock_guard<mutex> lock(mtx);
//         cout << "Status Pesanan: " << statusPesanan << endl;
//     }

//     void ubahStatusPesanan(const string& status) {
//         {
//             lock_guard<mutex> lock(mtx);
//             statusPesanan = status;
//         }
//         notify();
//     }

//     string getStatusPesanan() {
//         lock_guard<mutex> lock(mtx);
//         return statusPesanan;
//     }

//     bool getAvailableStatus() {
//         lock_guard<mutex> lock(mtx);
//         return isAvailable;
//     }

//     bool getPiringKotorStatus() {
//         lock_guard<mutex> lock(mtx);
//         return piringKotor;
//     }

//     void kosongkanMeja() {
//         lock_guard<mutex> lock(mtx);
//         isAvailable = true;
//         piringKotor = false;
//         statusPesanan = "Belum Diambil";
//         cout << "Meja sekarang kosong dan siap untuk pelanggan berikutnya.\n";
//     }

//     void isiMeja() {
//         lock_guard<mutex> lock(mtx);
//         isAvailable = false;
//     }

//     void piringKotorMeja() {
//         lock_guard<mutex> lock(mtx);
//         piringKotor = true;
//     }

//     void bersihkanPiring() {
//         lock_guard<mutex> lock(mtx);
//         piringKotor = false;
//         cout << "Piring kotor telah dibersihkan dari meja.\n";
//     }
//         mutex& getMutex() {
//         return mtx;
//     }
// };

// class Pelanggan {
// private:
//     int nilaiEmosi;
//     int kesabaran;
//     bool sabarHabis;
//     bool sudahDiberiPesanan;
//     mutable mutex mtx;

// public:
//     Pelanggan() : nilaiEmosi(5), kesabaran(30), sabarHabis(false), sudahDiberiPesanan(false) {}

//     void kurangiKesabaran() {
//         lock_guard<mutex> lock(mtx);
//         if (kesabaran > 0) {
//             kesabaran--;
//             if (kesabaran % 5 == 0 && nilaiEmosi > 1) {
//                 nilaiEmosi--;
//             }
//         } else {
//             sabarHabis = true;
//         }
//     }

//     bool isSabarHabis() const {
//         lock_guard<mutex> lock(mtx);
//         return sabarHabis;
//     }

//     int getEmosi() {
//         lock_guard<mutex> lock(mtx);
//         return nilaiEmosi;
//     }

//     bool sudahMendapatPesanan() {
//         lock_guard<mutex> lock(mtx);
//         return sudahDiberiPesanan;
//     }

//     void beriPesanan() {
//         lock_guard<mutex> lock(mtx);
//         sudahDiberiPesanan = true;
//         resetKesabaran();
//     }

//     void resetKesabaran() {
//         lock_guard<mutex> lock(mtx);
//         kesabaran = 30;
//         nilaiEmosi = 5;
//         sabarHabis = false;
//     }

//     void pergiDariMeja() {
//         cout << "Pelanggan sudah menerima pesanan dan pergi.\n";
//     }
// };

// class Pelayan : public Observer {
// public:
//     vector<Meja*> mejaList;
// public:
//     Pelayan(const vector<Meja*>& mejaList) : mejaList(mejaList) {
//         for (Meja* meja : mejaList) {
//             meja->addObserver(this);
//         }
//     }

//     ~Pelayan() {
//         for (Meja* meja : mejaList) {
//             meja->removeObserver(this);
//         }
//     }

//     void ambilPesanan(Meja& meja) {
//         if (meja.getStatusPesanan() == "Belum Diambil") {
//             meja.ubahStatusPesanan("Di Dapur");
//             cout << "Pelayan mengambil pesanan.\n";
//         } else {
//             cout << "Tidak ada pesanan yang dapat diambil atau sudah diambil.\n";
//         }
//     }

//     void antarPesanan(Meja& meja, Pelanggan& pelanggan) {
//         string statusPesanan = meja.getStatusPesanan();

//         if (statusPesanan == "Sudah Siap") {
//             meja.ubahStatusPesanan("Sudah Disajikan");
//             pelanggan.beriPesanan();
//             meja.piringKotorMeja();
//             cout << "Pelayan mengantarkan pesanan ke meja.\n";
//         } else {
//             cout << "Pesanan belum siap untuk diantar.\n";
//         }
//     }

//     void bersihkanMeja(Meja& meja) {
//         if (meja.getPiringKotorStatus()) {
//             meja.bersihkanPiring();
//         } else {
//             cout << "Tidak ada piring kotor di meja.\n";
//         }
//     }

//     void update() override {
//         for (Meja* meja : mejaList) {
//             if (meja->getStatusPesanan() == "Sudah Disajikan") {
//                 cout << "Pesanan di meja sudah disajikan!\n";
//             }
//         }
//     }
// };

// class Dapur {
// public:
//     void selesaikanPesanan(Meja& meja) {
//         if (meja.getStatusPesanan() == "Di Dapur") {
//             this_thread::sleep_for(chrono::seconds(2));
//             meja.ubahStatusPesanan("Sudah Siap");
//             cout << "Pesanan untuk meja sudah siap.\n";
//         }
//     }
// };

// void sistemKesabaran(Pelanggan& pelanggan, Meja& meja, bool& stopThread) {
//     pelanggan.resetKesabaran();
//     int previousEmosi = pelanggan.getEmosi();

//     while (!pelanggan.isSabarHabis() && !pelanggan.sudahMendapatPesanan()) {
//         {
//             lock_guard<mutex> lock(meja.getMutex());  // Lock the mutex
//             if (stopThread) {
//                 cout << "Pesanan telah diantarkan, thread sistemKesabaran dihentikan.\n";
//                 return;  // Exit the thread if stopThread is true
//             }
//         }

//         pelanggan.kurangiKesabaran();
//         int currentEmosi = pelanggan.getEmosi();

//         if (currentEmosi < previousEmosi) {
//             cout << "Kesabaran Pelanggan: " << currentEmosi << endl;
//             previousEmosi = currentEmosi;
//         }

//         this_thread::sleep_for(chrono::seconds(1));

//         if (pelanggan.isSabarHabis()) {
//             cout << "Pelanggan marah dan pergi!\n";
//             meja.kosongkanMeja();  // Ensure the table is cleared when the customer leaves
//             return;
//         }
//     }

//     if (pelanggan.sudahMendapatPesanan()) {
//         this_thread::sleep_for(chrono::seconds(5));  // Simulate customer leaving after serving
//         pelanggan.pergiDariMeja();
//         meja.kosongkanMeja();  // Mark the table as available again
//         cout << "Meja sekarang kosong dan siap untuk pelanggan berikutnya.\n";
//     }
// }


// void tampilkanMenu(queue<unique_ptr<Pelanggan>>& antrianPelanggan, vector<unique_ptr<Meja>>& daftarMeja, vector<Pelayan>& pelayan, Dapur& dapur1) {
//     int pilihan;
//     bool stopThread = false; // Flag to stop the patience countdown thread
//     thread t1;

//     do {
//         cout << "\n=== Menu Utama ===\n";
//         cout << "Pelanggan dalam antrian: " << antrianPelanggan.size() << "\n"; 
//         cout << "1. Taruh pelanggan ke meja\n";
//         cout << "2. Ambil pesanan pelanggan dan masak\n";
//         cout << "3. Antar pesanan ke meja\n";
//         cout << "4. Ambil piring kotor\n";
//         cout << "5. Keluar\n";
//         cout << "Pilih tindakan: ";
//         cin >> pilihan;

//         switch (pilihan) {
//         case 1: {
//             if (!antrianPelanggan.empty()) {
//                 for (size_t i = 0; i < daftarMeja.size(); ++i) {
//                     if (daftarMeja[i]->getAvailableStatus()) {
//                         daftarMeja[i]->isiMeja();
//                         unique_ptr<Pelanggan> pelanggan = move(antrianPelanggan.front());
//                         antrianPelanggan.pop();
                        
//                         // Start a new patience thread for the newly seated customer
//                         stopThread = false;
//                         if (t1.joinable()) t1.join();  // Ensure previous thread is joined
//                         t1 = thread(sistemKesabaran, ref(*pelanggan), ref(*daftarMeja[i]), ref(stopThread));
//                         cout << "Pelanggan ditempatkan di meja " << i << ".\n";
//                         break;
//                     }
//                 }
//             } else {
//                 cout << "Tidak ada pelanggan dalam antrian.\n";
//             }
//             break;
//         }
//         case 2: {
//             int mejaIndex;
//             cout << "Ambil pesanan dari meja (0 hingga " << daftarMeja.size() - 1 << "): ";
//             cin >> mejaIndex;
//             if (mejaIndex >= 0 && static_cast<size_t>(mejaIndex) < daftarMeja.size()) {
//                 pelayan[mejaIndex % pelayan.size()].ambilPesanan(*daftarMeja[mejaIndex]);
//                 dapur1.selesaikanPesanan(*daftarMeja[mejaIndex]);
//             } else {
//                 cout << "Meja tidak valid.\n";
//             }
//             break;
//         }
//         case 3: {
//             int mejaIndex;
//             cout << "Antar pesanan ke meja (0 hingga " << daftarMeja.size() - 1 << "): ";
//             cin >> mejaIndex;
//             if (mejaIndex >= 0 && static_cast<size_t>(mejaIndex) < daftarMeja.size()) {
//                 if (!antrianPelanggan.empty()) {
//                     pelayan[mejaIndex % pelayan.size()].antarPesanan(*daftarMeja[mejaIndex], *antrianPelanggan.front());
//                     stopThread = true;  // Stop the patience countdown when the order is served
//                     if (t1.joinable()) {
//                         t1.join();  // Ensure the thread is properly joined
//                     }
//                 } else {
//                     cout << "Tidak ada pelanggan di meja.\n";
//                 }
//             } else {
//                 cout << "Meja tidak valid.\n";
//             }
//             break;
//         }
//         case 4:
//             cout << "Piring kotor diambil dari meja.\n";
//             break;
//         case 5:
//             cout << "Keluar dari sistem.\n";
//             break;
//         default:
//             cout << "Pilihan tidak valid.\n";
//         }
//     } while (pilihan != 5);

//     if (t1.joinable()) {
//         t1.join();  // Join the thread if it's still running when exiting
//     }
// }


// int main() {
//     vector<unique_ptr<Meja>> daftarMeja;
//     for (int i = 0; i < 5; ++i) {
//         daftarMeja.push_back(make_unique<Meja>());
//     }

//     Pelayan pelayan1({ daftarMeja[0].get(), daftarMeja[1].get() });
//     Pelayan pelayan2({ daftarMeja[2].get(), daftarMeja[3].get(), daftarMeja[4].get() });

//     vector<Pelayan> pelayanList = { pelayan1, pelayan2 };

//     Dapur dapur1;

//     queue<unique_ptr<Pelanggan>> antrianPelanggan;
//     for (int i = 0; i < 4; ++i) {
//         antrianPelanggan.push(make_unique<Pelanggan>());
//     }

//     tampilkanMenu(antrianPelanggan, daftarMeja, pelayanList, dapur1);

//     return 0;
// }

#include "Meja.h"
#include "Pelayan.h"
#include "Pelanggan.h"
#include "Dapur.h"
#include <queue>
#include <vector>
#include <iostream>
#include <memory>

void tampilkanMenu(std::queue<std::unique_ptr<Pelanggan>>& antrianPelanggan, std::vector<std::unique_ptr<Meja>>& daftarMeja, std::vector<Pelayan>& pelayan, Dapur& dapur1);

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
void tampilkanMenu(std::queue<std::unique_ptr<Pelanggan>>& antrianPelanggan, std::vector<std::unique_ptr<Meja>>& daftarMeja, std::vector<Pelayan>& pelayan, Dapur& dapur1) {
    int pilihan;

    do {
        std::cout << "\n=== Menu Utama ===\n";
        std::cout << "Pelanggan dalam antrian: " << antrianPelanggan.size() << "\n"; 
        std::cout << "1. Taruh pelanggan ke meja\n";
        std::cout << "2. Ambil pesanan pelanggan dan masak\n";
        std::cout << "3. Antar pesanan ke meja\n";
        std::cout << "4. Ambil piring kotor\n";
        std::cout << "5. Keluar\n";
        std::cout << "Pilih tindakan: ";
        std::cin >> pilihan;

        switch (pilihan) {
       case 1: {
    if (!antrianPelanggan.empty()) {
        bool pelangganDitempatkan = false;  // Flag untuk melacak apakah pelanggan ditempatkan
        for (size_t i = 0; i < daftarMeja.size(); ++i) {
            if (daftarMeja[i]->getAvailableStatus()) {  // Jika meja tersedia
                if (daftarMeja[i]->getPiringKotorStatus()) {  // Cek apakah meja kotor
                    std::cout << "Meja " << i << " masih kotor. Lewati meja ini.\n";
                } else {
                    // Tempatkan pelanggan di meja yang bersih
                    Pelanggan* pelanggan = antrianPelanggan.front().get(); // Ambil pelanggan dari antrian
                    daftarMeja[i]->isiMeja(pelanggan); // Tempatkan pelanggan di meja
                    antrianPelanggan.pop(); // Hapus pelanggan dari antrian setelah ditempatkan
                    std::cout << "Pelanggan ditempatkan di meja " << i << ".\n";
                    pelangganDitempatkan = true;  // Tanda bahwa pelanggan berhasil ditempatkan
                    break;
                }
            }
        }
        if (!pelangganDitempatkan) {
            std::cout << "Tidak ada meja yang bersih dan tersedia.\n";
        }
    } else {
        std::cout << "Tidak ada pelanggan dalam antrian.\n";
    }
    break;
}


        case 2: {
            int mejaIndex;
            std::cout << "Ambil pesanan dari meja (0 hingga " << daftarMeja.size() - 1 << "): ";
            std::cin >> mejaIndex;
            if (mejaIndex >= 0 && static_cast<size_t>(mejaIndex) < daftarMeja.size()) {
                pelayan[mejaIndex % pelayan.size()].ambilPesanan(*daftarMeja[mejaIndex]);
                dapur1.selesaikanPesanan(*daftarMeja[mejaIndex]);
            } else {
                std::cout << "Meja tidak valid.\n";
            }
            break;
        }
       case 3: {
    int mejaIndex;
    std::cout << "Antar pesanan ke meja (0 hingga " << daftarMeja.size() - 1 << "): ";
    std::cin >> mejaIndex;
    if (mejaIndex >= 0 && static_cast<size_t>(mejaIndex) < daftarMeja.size()) {
        Meja* meja = daftarMeja[mejaIndex].get();

        if (meja->adaPelangganDiMeja()) {
            Pelanggan* pelanggan = meja->getPelanggan(); // Dapatkan pelanggan dari meja
            pelayan[mejaIndex % pelayan.size()].antarPesanan(*meja, *pelanggan);

            pelanggan->pergiDariMeja(); // Pelanggan pergi setelah menerima pesanan
            meja->kosongkanMeja();      // Kosongkan meja setelah pelanggan pergi
        } else {
            std::cout << "Tidak ada pelanggan di meja.\n";
        }
    } else {
        std::cout << "Meja tidak valid.\n";
    }
    break;
}


        case 4: {
            int mejaIndex;
            std::cout << "Ambil piring kotor dari meja (0 hingga " << daftarMeja.size() - 1 << "): ";
            std::cin >> mejaIndex;
            if (mejaIndex >= 0 && static_cast<size_t>(mejaIndex) < daftarMeja.size()) {
                pelayan[mejaIndex % pelayan.size()].bersihkanMeja(*daftarMeja[mejaIndex]);
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
