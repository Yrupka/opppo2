#ifndef MODE_H
#define MODE_H

struct Mode {
  int vertically, horizontally;
  bool rotated;
  Mode (int vertically_, int horizontally_, bool rotated_) :
    vertically(vertically_), horizontally(horizontally_), rotated(rotated_) {
  }
};

#endif // MODE_H
