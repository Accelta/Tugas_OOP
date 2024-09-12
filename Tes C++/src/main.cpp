#include "Meja.h"
#include "Pelanggan.h"
#include "Pelayan.h"
#include "Dapur.h"
#include <thread>
#include <chrono>

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
