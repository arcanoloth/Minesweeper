
#include "Board.h"
#include "Tile.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Board::Board() {
  has_won = false;
  has_lost = false;
  board_width = 8;
  board_height = 8;
  mine_count = 10;
  revealed_count = 0;
  size = board_width * board_height;
  boardtiles = new Tile[size];
  for (int i = 0; i < size; i++) {
    boardtiles[i].set_value(0);
  }
  place_mines();
}

Board::Board(int bh, int bw, int mc) {
  has_won = false;
  has_lost = false;
  board_width = bw;
  board_height = bh;
  mine_count = mc;
  revealed_count = 0;
  size = board_width * board_height;
  boardtiles = new Tile[size];

  for (int i = 0; i < size; i++) {
    boardtiles[i].set_value(0);
  }
  place_mines();
}

void Board::place_mines() {
  std::srand(std::time(0));
  for (int i = 0; i < mine_count; i++) {
    int row = (rand() % board_height);
    int col = (rand() % board_width);
    if (boardtiles[board_width * row + col].get_value() != -1) {
      boardtiles[board_width * row + col].set_value(-1);
      if (row - 1 >= 0) {
        if (col - 1 >= 0) {
          update_counts(row - 1, col - 1);
        }
        if (col + 1 < board_width) {
          update_counts(row - 1, col + 1);
        }

        update_counts(row - 1, col);
      }
      if (row + 1 < board_height) {
        if (col - 1 >= 0) {
          update_counts(row + 1, col - 1);
        }

        update_counts(row + 1, col);
        if (col + 1 < board_width) {
          update_counts(row + 1, col + 1);
        }
      }
      if (col - 1 >= 0) {
        update_counts(row, col - 1);
      }
      if (col + 1 < board_width) {
        update_counts(row, col + 1);
      }
    } else {
      i--;
    }
  }
}

void Board::update_counts(int row, int col) {
  if ((row >= 0) && row < board_height && (col >= 0) && col < board_width) {
    if (boardtiles[board_width * row + col].get_value() != -1) {
      boardtiles[board_width * row + col].set_value(
          boardtiles[board_width * row + col].get_value() + 1);
    }
  }
}

void Board::display_revealed() {
  for (int i = 0; i < size; i++) {
    boardtiles[i].set_revealed(true);
  }
  print();
};

bool Board::get_lost() { return has_lost; };
bool Board::get_won() { return has_won; };

void Board::print() {
  std::cout << "    ";
  for (int j = 0; j < board_width; j++) {
    std::cout << j << "   ";
  }
  std::cout << std::endl;
  for (int i = 0; i < board_height; i++) {
    std::cout << "  ";
    for (int j = 0; j < board_width; j++) {
      std::cout << "|---";
    }
    std::cout << "|";
    std::cout << std::endl;
    std::cout << i << " ";
    for (int j = 0; j < board_width; j++) {
      std::cout << "| ";
      boardtiles[board_width * i + j].display();
      std::cout << " ";
    }
    std::cout << "|";
    std::cout << std::endl;
  }
  std::cout << "  ";
  for (int j = 0; j < board_width; j++) {
    std::cout << "|---";
  }
  std::cout << "|";
  std::cout << std::endl;
}

void Board::reveal(int row, int col) {
  if (Board::validate(row, col)) {
    if (boardtiles[board_width * row + col].get_value() == -1) {
      has_lost = true;
      return;
    }
    if (!boardtiles[board_width * row + col].get_revealed()) {
      boardtiles[board_width * row + col].set_revealed(true);
      revealed_count++;
      if (revealed_count == size - mine_count) {
        has_won = true;
      }
    }
  }
}

bool Board::validate(int row, int col) {
  if ((row >= 0) && (row < this->board_height) && (col >= 0) &&
      (col < this->board_width)) {
    return true;
  } else {
    return false;
  }
}

Board::~Board() { delete[] boardtiles; }
