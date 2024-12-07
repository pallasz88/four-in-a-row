#include <cstdint>

// Define constants for board size and player IDs
const int BOARD_SIZE = 7;
const uint64_t PLAYER_X = 1;
const uint64_t PLAYER_O = 2;

class Game {
public:
  // Constructor to initialize the game state
  Game() : board_(0) {}

  // Method to place a piece on the board
  void placePiece(uint64_t player, int column) {
    // TO DO: implement logic to place piece at bottom of column
  }

private:
  uint64_t board_;
};

// Function to print the game state (for debugging purposes)
void printBoard(const Game& game) {
  // TO DO: implement logic to print the game state
}

int main() {
  Game game;
  return 0;
}
