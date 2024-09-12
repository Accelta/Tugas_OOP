#include "Meja.h"
#include "Pelanggan.h"
#include "Pelayan.h"
#include "Dapur.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <windows.h> // For Windows key handling

std::thread threadEmosi; // Declare globally to manage the emotion thread
bool gameOver = false;   // Global variable to track if the game is over
bool orderTaken = false; // Track if an order has been taken
bool orderReady = false; // Track if the order is ready to deliver

// Simulate decreasing customer emotion over time
void emosiPelangganTurun(Pelanggan& pelanggan) {
    while (pelanggan.getEmosi() > 1 && !gameOver) {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Emotion decreases every 2 seconds
        pelanggan.kurangiEmosi();
        pelanggan.tampilkanEmosi();
    }

    // If emotion is depleted, end the game
    if (pelanggan.getEmosi() == 1) {
        std::cout << "Emosi pelanggan habis! Game Over!\n";
        gameOver = true;
    }
}

// Function to reset the table and customer for the next round
void pelangganBaru(Meja& meja, Pelanggan& pelanggan) {
    if (gameOver) return; // Do nothing if the game is over

    std::cout << "\nPelanggan baru datang!" << std::endl;
    meja.ubahStatusPesanan("Belum Diambil");  // Reset table status
    pelanggan.resetEmosi();                   // Reset customer emotion

    // Reset order status flags
    orderTaken = false;
    orderReady = false;

    // Join the previous thread and start a new thread for the new customer
    if (threadEmosi.joinable()) {
        threadEmosi.join(); // Ensure the previous emotion thread finishes
    }
    threadEmosi = std::thread(emosiPelangganTurun, std::ref(pelanggan)); // Start new emotion depletion thread
}

int main() {
    Meja meja1;
    Pelanggan pelanggan1;
    Pelayan pelayan1;
    Dapur dapur1;

    // Start the emotion depletion thread for the first customer
    threadEmosi = std::thread(emosiPelangganTurun, std::ref(pelanggan1));

    bool gameRunning = true;

    while (gameRunning && !gameOver) { // Add gameOver check in the game loop
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

    // Clean up the emotion thread when exiting the game
    if (threadEmosi.joinable()) {
        threadEmosi.join(); // Ensure the emotion thread is properly finished
    }

    std::cout << "Terima kasih sudah bermain!" << std::endl;
    return 0;
}
