# Four in a row

This repo will be a C++ implementation of the game 4 in a row.

## Game rules
1. The game is played by two players using a vertical game board with 6 rows and 7 columns, totaling 42 cells.
2. The players take turns placing their colored game pieces (usually red and yellow) into the columns of the game board.
3. Once a game piece is placed into a column, it falls to the lowest available cell in that column due to gravity.
4. The first player to connect four of their game pieces vertically, horizontally, or diagonally wins the game.
5. If all cells of the game board are filled without either player achieving four in a row, the game ends in a draw.

## Implementation

* Bitboard for each player (42 bits)
* Neural network based engine
* Qt GUI

## Board representation

|  A |  B |  C |  D |  E |  F |  G |
| -- | -- | -- | -- | -- | -- | -- |
| 35 | 36 | 37 | 38 | 39 | 40 | 41 |
| 28 | 29 | 30 | 31 | 32 | 33 | 34 |
| 21 | 22 | 23 | 24 | 25 | 26 | 27 |
| 14 | 15 | 16 | 17 | 18 | 19 | 20 |
|  7 |  8 |  9 | 10 | 11 | 12 | 13 |
|  0 |  1 |  2 |  3 |  4 |  5 |  6 |

## Move representation

Each player can choose one column at their turn, so it is enough to choose a letter to its corresponding column. 
Move generation is pretty simple. Every turn there is 7 possible moves (for every column), until the column is not filled up. Then that column turns to unavailable.