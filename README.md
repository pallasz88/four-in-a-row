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
* Working game rules
