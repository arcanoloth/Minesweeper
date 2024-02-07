#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include <array>

class Board {
private:
  bool has_won, has_lost;
  int board_width, board_height, mine_count, revealed_count, size;
  Tile *boardtiles;
  void place_mines();
  void update_counts(int, int);
  bool validate(int row, int col);

public:
  void display_revealed();
  bool get_lost();
  bool get_won();
  void print();
  void reveal(int row, int col);
  Board();
  Board(int, int, int);
  ~Board();
};

#endif /* BOARD_H */