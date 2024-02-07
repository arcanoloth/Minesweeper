#include "Board.h"
#include "Tile.h"
#include <iostream>

int main() {
  int row, rows, column, columns, mine_count;
  std::cout << "Enter a board size rows followed by columns: ";
  std::cin >> rows >> columns;
  std::cout << std::endl;
  std::cout << "Enter number of mines for custom difficulty: ";
  std::cin >> mine_count;
  Board play_area(rows, columns, mine_count);
  while (true) {
    play_area.print();
    std::cout << "Enter a row and column to dig: ";
    std::cin >> row >> column;
    play_area.reveal(row, column);
    if (play_area.get_won()) {
      std::cout << "YOU'VE WON!!!";
      std::cout << std::endl;
      std::cout << "Final Board:";
      std::cout << std::endl;
      play_area.print();
      return 0;
    }
    if (play_area.get_lost()) {
      std::cout << "YOU'VE LOST!!!!!!!";
      std::cout << std::endl;
      std::cout << "Final Board:";
      std::cout << std::endl;
      play_area.display_revealed();
      return 0;
    }
  }
}