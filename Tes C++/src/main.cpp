#include "Meja.h"
#include "Pelanggan.h"
#include "Pelayan.h"
#include "Dapur.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <windows.h> // For Windows key handling

// Simulate decreasing customer emotion over time
void emosiPelangganTurun(Pelanggan& pelanggan) {
    while (pelanggan.getEmosi() > 1) {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Emotion decreases every 2 seconds
        pelanggan.kurangiEmosi();
        pelanggan.tampilkanEmosi();
    }
}

// Function to reset the table and customer for the next round
void pelangganBaru(Meja& meja, Pelanggan& pelanggan) {
    std::cout << "\nPelanggan baru datang!" << std::endl;
    meja.ubahStatusPesanan("Belum Diambil");  // Reset table status
    pelanggan.resetEmosi();                   // Reset customer emotion
}

int main() {
    Meja meja1;
    Pelanggan pelanggan1;
    Pelayan pelayan1;
    Dapur dapur1;

    // Start a thread to simulate customer's emotion decreasing over time
    std::thread threadEmosi(emosiPelangganTurun, std::ref(pelanggan1));

    bool gameRunning = true;
    bool orderTaken = false;
    bool orderReady = false;

    while (gameRunning) {
        // Check for 'F' key to take order
        if (GetAsyncKeyState('F') & 0x8000) { // If the 'F' key is pressed
            if (!orderTaken) {
                pelayan1.ambilPesanan(meja1);
                pelayan1.kirimPesananKeDapur();
                meja1.tampilkanStatusPesanan();
                dapur1.mulaiMemasak();  // Simulate cooking
                dapur1.selesaiPesanan(meja1);
                orderTaken = true;
                orderReady = true;
            }
        }

        // Check for 'D' key to deliver order
        if (GetAsyncKeyState('D') & 0x8000) { // If the 'D' key is pressed
            if (orderReady) {
                pelayan1.antarPesanan(meja1, pelanggan1);
                meja1.tampilkanStatusPesanan();
                orderReady = false;
                orderTaken = false;

                // Introduce a new customer after the order is delivered
                pelangganBaru(meja1, pelanggan1);
            }
        }

        // Exit the game loop with 'Esc' key
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { // If 'Esc' key is pressed
            gameRunning = false;
        }

        // Sleep for a short while to avoid excessive CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Wait for the emotion thread to finish
    threadEmosi.join();

    return 0;
}
