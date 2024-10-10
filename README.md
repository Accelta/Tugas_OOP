Nama kelompok : 1. Axel Thariq Anggara ( 5223600085 )
                2. Mochammad Denny Yulianto ( 5223600079 )

# Dinner Dash Style Game

This is a simple Dinner Dash-style game implemented in C++ where the player takes and delivers customer orders. The game introduces new customers, tracks their emotions, and ends if a customer's emotion is depleted.

## Features
- **Order System**: The player can take orders from customers by pressing `F` and deliver orders by pressing `D`.
- **Emotion System**: Customers have an emotion that decreases over time. If the emotion reaches 1, the game ends.
- **Game Over Condition**: The game ends when a customer's emotion is depleted.
- **New Customers**: After each order is served, a new customer arrives.

## Controls
- **F**: Take an order from the customer.
- **D**: Deliver an order to the customer.
- **Esc**: Exit the game.

## Dependencies
- **Windows**: The game uses `GetAsyncKeyState` from the `Windows.h` library to capture key presses.

## How to Build and Run

1. **Clone the repository** or download the source code.
2. **Build**: 
   - On **Windows**, compile the code using a C++ compiler (e.g., g++, Visual Studio, or another compiler). Example compilation command using `g++`:
     ```bash
     g++ src/*.cpp -o (exename)
     ```
3. **Run**: Execute the compiled binary:
   ```bash
   ./game
or click the exe file that sucessfully builded

