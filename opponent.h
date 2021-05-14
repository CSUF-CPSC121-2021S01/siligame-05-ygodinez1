#include <iostream>
#include <string>
#include <iostream>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include <memory>

#ifndef OPPONENT_H
#define OPPONENT_H

class Opponent : public GameElement {
 public:
  Opponent() : GameElement(0, 0, 50, 50) {}
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image& opponent_image) {
    opponent_image.DrawRectangle(x_ + 16, y_ + 46, 6, 1, 126, 105, 89);
    opponent_image.DrawRectangle(x_ + 24, y_ + 46, 6, 1, 126, 105, 89);
    opponent_image.DrawRectangle(x_ + 21, y_ + 45, 1, 1, 126, 105, 89);
    opponent_image.DrawRectangle(x_ + 28, y_ + 45, 2, 1, 126, 105, 89);

    opponent_image.DrawRectangle(x_ + 17, y_ + 45, 4, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 18, y_ + 44, 2, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 25, y_ + 45, 3, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 26, y_ + 44, 2, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 27, y_ + 43, 1, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 13, y_ + 29, 3, 2, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 14, y_ + 28, 2, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 14, y_ + 26, 3, 2, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 15, y_ + 25, 2, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 15, y_ + 24, 3, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 18, y_ + 23, 1, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 20, y_ + 31, 6, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 21, y_ + 30, 1, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 23, y_ + 30, 3, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 29, y_ + 23, 1, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 27, y_ + 24, 4, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 28, y_ + 25, 3, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 29, y_ + 26, 3, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 30, y_ + 27, 2, 2, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 29, y_ + 29, 3, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 28, y_ + 30, 4, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 29, y_ + 31, 2, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 20, y_ + 19, 5, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 21, y_ + 18, 3, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 19, y_ + 17, 7, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 17, y_ + 16, 12, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 16, y_ + 15, 14, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 16, y_ + 14, 5, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 23, y_ + 14, 1, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 25, y_ + 13, 5, 2, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 16, y_ + 13, 4, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 15, y_ + 12, 15, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 15, y_ + 10, 16, 2, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 15, y_ + 7, 4, 3, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 22, y_ + 7, 2, 3, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 27, y_ + 8, 4, 2, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 27, y_ + 7, 3, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 16, y_ + 6, 14, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 16, y_ + 5, 13, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 17, y_ + 4, 11, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 19, y_ + 3, 7, 1, 76, 101, 75);
    opponent_image.DrawRectangle(x_ + 21, y_ + 2, 3, 1, 76, 101, 75);

    opponent_image.DrawRectangle(x_ + 17, y_ + 44, 1, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 17, y_ + 43, 3, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 18, y_ + 42, 3, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 18, y_ + 41, 4, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 19, y_ + 40, 4, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 20, y_ + 39, 3, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 19, y_ + 38, 4, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 19, y_ + 37, 3, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 19, y_ + 36, 2, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 18, y_ + 35, 4, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 18, y_ + 34, 11, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 19, y_ + 33, 9, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 20, y_ + 32, 7, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 24, y_ + 35, 5, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 24, y_ + 36, 4, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 25, y_ + 37, 3, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 25, y_ + 38, 4, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 26, y_ + 39, 3, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 26, y_ + 40, 2, 1, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 25, y_ + 41, 3, 2, 46, 58, 103);
    opponent_image.DrawRectangle(x_ + 26, y_ + 43, 1, 1, 46, 58, 103);

    opponent_image.DrawRectangle(x_ + 19, y_ + 31, 1, 1, 120, 120, 120);
    opponent_image.DrawRectangle(x_ + 19, y_ + 30, 2, 1, 120, 120, 120);
    opponent_image.DrawRectangle(x_ + 22, y_ + 30, 1, 1, 120, 120, 120);
    opponent_image.DrawRectangle(x_ + 19, y_ + 28, 7, 2, 120, 120, 120);
    opponent_image.DrawRectangle(x_ + 20, y_ + 25, 6, 3, 120, 120, 120);
    opponent_image.DrawRectangle(x_ + 19, y_ + 23, 6, 2, 120, 120, 120);
    opponent_image.DrawRectangle(x_ + 16, y_ + 23, 2, 1, 120, 120, 120);
    opponent_image.DrawRectangle(x_ + 16, y_ + 22, 13, 1, 120, 120, 120);
    opponent_image.DrawRectangle(x_ + 17, y_ + 21, 11, 1, 120, 120, 120);
    opponent_image.DrawRectangle(x_ + 18, y_ + 20, 10, 1, 120, 120, 120);
    opponent_image.DrawRectangle(x_ + 19, y_ + 19, 1, 1, 120, 120, 120);
    opponent_image.DrawRectangle(x_ + 25, y_ + 19, 1, 1, 120, 120, 120);
    opponent_image.DrawRectangle(x_ + 26, y_ + 23, 3, 1, 120, 120, 120);

    opponent_image.DrawRectangle(x_ + 20, y_ + 13, 5, 1, 146, 144, 55);
    opponent_image.DrawRectangle(x_ + 21, y_ + 14, 2, 1, 146, 144, 55);
    opponent_image.DrawRectangle(x_ + 24, y_ + 14, 1, 1, 146, 144, 55);
    opponent_image.DrawRectangle(x_ + 19, y_ + 8, 3, 2, 146, 144, 55);
    opponent_image.DrawRectangle(x_ + 20, y_ + 7, 2, 1, 146, 144, 55);
    opponent_image.DrawRectangle(x_ + 24, y_ + 7, 2, 3, 146, 144, 55);
    opponent_image.DrawRectangle(x_ + 26, y_ + 7, 1, 1, 146, 144, 55);
    opponent_image.DrawRectangle(x_ + 26, y_ + 9, 1, 1, 146, 144, 55);

    opponent_image.DrawRectangle(x_ + 19, y_ + 7, 1, 1, 0, 0, 0);
    opponent_image.DrawRectangle(x_ + 26, y_ + 8, 1, 1, 0, 0, 0);
  }

  void Move(const graphics::Image& image) {
    x_ += 3;
    y_ += 3;
    if (IsOutOfBounds(image) == true) {
      is_active_ = false;
    }
  }

  std::unique_ptr<class OpponentProjectile> LaunchProjectile() {
      std::unique_ptr<OpponentProjectile> new_projectile;
      if(count % 20 == 0) {
          new_projectile = std::make_unique<OpponentProjectile>(x_ + 25, y_ + 20);          
      } else {
          new_projectile = nullptr;
          count++;
      }
      return std::move(new_projectile);
  }
 
  private:
    int count;
};

#endif

#ifndef OPPONENT_PROJECTILE_H
#define OPPONENT_PROJECTILE_H

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() : GameElement(0, 0, 50, 50) {}
  OpponentProjectile(int x, int y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image& oprojectile_image) {
    oprojectile_image.DrawRectangle(x_ + 0, y_ + 0, 5, 1, 238, 167, 72);
    oprojectile_image.DrawRectangle(x_ + 0, y_ + 4, 5, 1, 238, 167, 72);
    oprojectile_image.DrawRectangle(x_ + 0, y_ + 1, 5, 1, 255, 0, 0);
    oprojectile_image.DrawRectangle(x_ + 0, y_ + 2, 5, 1, 88, 56, 21);
    oprojectile_image.DrawRectangle(x_ + 0, y_ + 3, 5, 1, 0, 131, 4);
  }

  void Move(const graphics::Image& image) {
    y_ += 3;
    if (IsOutOfBounds(image) == true) {
      is_active_ = false;
    }
  }
};

#endif
