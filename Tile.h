#ifndef TILE_H
#define TILE_H

class Tile {
private:
  int value;
  bool revealed;

public:
  void display();
  bool get_revealed();
  void set_revealed(bool);
  int get_value();
  void set_value(int);
  Tile();
};

#endif /* TILE_H */