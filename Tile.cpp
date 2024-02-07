
#include "Tile.h"
#include <iostream>

void Tile::display() {
  if (revealed == false) {
    std::cout << "#";
  } else if (value == -1) {
    std::cout << "M";
  } else {
    std::cout << value;
  }
};

bool Tile::get_revealed() { return revealed; };

void Tile::set_revealed(bool r) { revealed = r; };

int Tile::get_value() { return value; };

void Tile::set_value(int v) { value = v; };

Tile::Tile() {
  value = 0;
  revealed = false;
};
