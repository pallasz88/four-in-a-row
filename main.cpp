/* Copyright 2023 Laszlo Paal. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include <iostream>
#include <string>
#include <vector>

// Function to print the board
void printBoard(const std::vector<std::string> &board) {
  for (const auto &row : board) {
    for (const auto &tile : row) {
      std::cout << tile << '|';
    }
    std::cout << '\n';
  }
}

// Function to check for a win
bool checkWin(const std::vector<std::string> &board, char player) {
  const int rows = board.size();
  const int cols = board[0].size();

  // Check horizontal
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols - 3; ++col) {
      if (board[row][col] == player && board[row][col + 1] == player &&
          board[row][col + 2] == player && board[row][col + 3] == player) {
        return true;
      }
    }
  }

  // Check vertical
  for (int col = 0; col < cols; ++col) {
    for (int row = 0; row < rows - 3; ++row) {
      if (board[row][col] == player && board[row + 1][col] == player &&
          board[row + 2][col] == player && board[row + 3][col] == player) {
        return true;
      }
    }
  }

  // Check diagonal (bottom-left to top-right)
  for (int row = 3; row < rows; ++row) {
    for (int col = 0; col < cols - 3; ++col) {
      if (board[row][col] == player && board[row - 1][col + 1] == player &&
          board[row - 2][col + 2] == player &&
          board[row - 3][col + 3] == player) {
        return true;
      }
    }
  }

  // Check anti-diagonal (top-left to bottom-right)
  for (int row = 0; row < rows - 3; ++row) {
    for (int col = 0; col < cols - 3; ++col) {
      if (board[row][col] == player && board[row + 1][col + 1] == player &&
          board[row + 2][col + 2] == player &&
          board[row + 3][col + 3] == player) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  // Initialize the board with empty strings
  const int rows = 6;
  const int cols = 7;
  std::vector<std::string> board(rows, std::string(cols, ' '));

  char playerTurn = 'X';
  bool gameOver = false;

  while (!gameOver) {
    // Print the current state of the board
    printBoard(board);

    // Get the column from the user
    int col;
    std::cout << "Player " << playerTurn << ", enter a column: ";
    std::cin >> col;

    // Check if the column is valid
    if (col < 1 || col > cols) {
      std::cerr << "Invalid column. Please try again.\n";
      continue;
    }

    // Find an empty spot in the column
    bool validMove = false;
    for (int row = rows - 1; row >= 0; --row) {
      if (board[row][col - 1] == ' ') {
        board[row][col - 1] = playerTurn;
        validMove = true;

        // Check for a win
        if (checkWin(board, playerTurn)) {
          printBoard(board);
          std::cout << "Player " << playerTurn << " wins!\n";
          gameOver = true;
        }

        // Switch player turn
        playerTurn = (playerTurn == 'X') ? 'O' : 'X';
        break;
      }
    }

    if (!validMove) {
      std::cout << "Invalid move. Please try again.\n";
    }
  }

  return 0;
}
