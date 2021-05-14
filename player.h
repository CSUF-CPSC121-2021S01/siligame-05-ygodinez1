#include <iostream>
#include <memory>
#include <string>
#include "cpputils/graphics/image.h"
#include "opponent.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public GameElement {
 public:
  Player() : GameElement(0, 0, 50, 50) {}
  Player(int x, int y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image& player_image) {
    player_image.SetRed(15, 46, 0);
    player_image.SetGreen(15, 46, 0);
    player_image.SetBlue(15, 46, 0);

    player_image.DrawRectangle(x_ + 15, y_ + 46, 7, 3, 0, 0, 0);
    player_image.DrawRectangle(x_ + 24, y_ + 46, 7, 3, 0, 0, 0);

    player_image.DrawRectangle(x_ + 18, y_ + 36, 4, 10, 18, 18, 18);
    player_image.DrawRectangle(x_ + 24, y_ + 36, 4, 10, 18, 18, 18);

    player_image.DrawRectangle(x_ + 9, y_ + 30, 1, 7, 169, 12, 12);
    player_image.DrawRectangle(x_ + 10, y_ + 29, 1, 7, 169, 12, 12);
    player_image.DrawRectangle(x_ + 11, y_ + 27, 1, 9, 169, 12, 12);
    player_image.DrawRectangle(x_ + 12, y_ + 30, 1, 7, 169, 12, 12);
    player_image.DrawRectangle(x_ + 13, y_ + 30, 1, 6, 169, 12, 12);
    player_image.DrawRectangle(x_ + 14, y_ + 30, 1, 6, 169, 12, 12);
    player_image.DrawRectangle(x_ + 15, y_ + 27, 1, 10, 169, 12, 12);
    player_image.DrawRectangle(x_ + 16, y_ + 25, 1, 11, 169, 12, 12);
    player_image.DrawRectangle(x_ + 12, y_ + 25, 1, 2, 169, 12, 12);
    player_image.DrawRectangle(x_ + 13, y_ + 23, 1, 2, 169, 12, 12);
    player_image.DrawRectangle(x_ + 14, y_ + 22, 1, 1, 169, 12, 12);
    player_image.DrawRectangle(x_ + 15, y_ + 21, 1, 1, 169, 12, 12);
    player_image.DrawRectangle(x_ + 16, y_ + 20, 1, 1, 169, 12, 12);
    player_image.DrawRectangle(x_ + 17, y_ + 18, 1, 2, 169, 12, 12);
    player_image.DrawRectangle(x_ + 18, y_ + 16, 1, 3, 169, 12, 12);
    player_image.DrawRectangle(x_ + 19, y_ + 17, 1, 2, 169, 12, 12);
    player_image.DrawRectangle(x_ + 22, y_ + 21, 2, 2, 169, 12, 12);
    player_image.DrawRectangle(x_ + 22, y_ + 21, 2, 2, 169, 12, 12);
    player_image.DrawRectangle(x_ + 22, y_ + 24, 2, 2, 169, 12, 12);
    player_image.DrawRectangle(x_ + 22, y_ + 27, 2, 2, 169, 12, 12);
    player_image.DrawRectangle(x_ + 26, y_ + 17, 1, 2, 169, 12, 12);
    player_image.DrawRectangle(x_ + 27, y_ + 16, 1, 3, 169, 12, 12);
    player_image.DrawRectangle(x_ + 28, y_ + 18, 1, 2, 169, 12, 12);
    player_image.DrawRectangle(x_ + 29, y_ + 20, 1, 1, 169, 12, 12);
    player_image.DrawRectangle(x_ + 30, y_ + 21, 1, 1, 169, 12, 12);
    player_image.DrawRectangle(x_ + 31, y_ + 22, 1, 1, 169, 12, 12);
    player_image.DrawRectangle(x_ + 32, y_ + 23, 1, 2, 169, 12, 12);
    player_image.DrawRectangle(x_ + 33, y_ + 25, 1, 2, 169, 12, 12);
    player_image.DrawRectangle(x_ + 29, y_ + 25, 1, 11, 169, 12, 12);
    player_image.DrawRectangle(x_ + 30, y_ + 27, 1, 10, 169, 12, 12);
    player_image.DrawRectangle(x_ + 31, y_ + 30, 2, 6, 169, 12, 12);
    player_image.DrawRectangle(x_ + 33, y_ + 30, 1, 7, 169, 12, 12);
    player_image.DrawRectangle(x_ + 34, y_ + 27, 1, 9, 169, 12, 12);
    player_image.DrawRectangle(x_ + 35, y_ + 29, 1, 7, 169, 12, 12);
    player_image.DrawRectangle(x_ + 36, y_ + 30, 1, 7, 169, 12, 12);

    player_image.DrawRectangle(x_ + 20, y_ + 35, 6, 1, 0, 0, 0);
    player_image.DrawRectangle(x_ + 17, y_ + 20, 3, 16, 0, 0, 0);
    player_image.DrawRectangle(x_ + 26, y_ + 20, 3, 16, 0, 0, 0);
    player_image.DrawRectangle(x_ + 18, y_ + 19, 2, 1, 0, 0, 0);
    player_image.DrawRectangle(x_ + 26, y_ + 19, 2, 1, 0, 0, 0);
    player_image.DrawRectangle(x_ + 12, y_ + 27, 3, 2, 0, 0, 0);
    player_image.DrawRectangle(x_ + 13, y_ + 25, 3, 2, 0, 0, 0);
    player_image.DrawRectangle(x_ + 14, y_ + 23, 3, 2, 0, 0, 0);
    player_image.DrawRectangle(x_ + 15, y_ + 22, 2, 1, 0, 0, 0);
    player_image.DrawRectangle(x_ + 16, y_ + 21, 1, 1, 0, 0, 0);
    player_image.DrawRectangle(x_ + 29, y_ + 21, 1, 1, 0, 0, 0);
    player_image.DrawRectangle(x_ + 29, y_ + 22, 2, 1, 0, 0, 0);
    player_image.DrawRectangle(x_ + 29, y_ + 23, 3, 2, 0, 0, 0);
    player_image.DrawRectangle(x_ + 30, y_ + 25, 3, 2, 0, 0, 0);
    player_image.DrawRectangle(x_ + 31, y_ + 27, 3, 2, 0, 0, 0);
    player_image.DrawRectangle(x_ + 21, y_ + 16, 1, 4, 0, 0, 0);
    player_image.DrawRectangle(x_ + 24, y_ + 16, 1, 4, 0, 0, 0);
    player_image.DrawRectangle(x_ + 22, y_ + 17, 2, 2, 0, 0, 0);
    player_image.DrawRectangle(x_ + 20, y_ + 12, 6, 1, 0, 0, 0);
    player_image.DrawRectangle(x_ + 20, y_ + 8, 2, 2, 0, 0, 0);
    player_image.DrawRectangle(x_ + 24, y_ + 8, 2, 2, 0, 0, 0);
    player_image.DrawRectangle(x_ + 16, y_ + 4, 1, 6, 0, 0, 0);
    player_image.DrawRectangle(x_ + 17, y_ + 3, 1, 5, 0, 0, 0);
    player_image.DrawRectangle(x_ + 18, y_ + 2, 10, 3, 0, 0, 0);
    player_image.DrawRectangle(x_ + 22, y_ + 5, 2, 1, 0, 0, 0);
    player_image.DrawRectangle(x_ + 28, y_ + 3, 1, 5, 0, 0, 0);
    player_image.DrawRectangle(x_ + 29, y_ + 4, 1, 6, 0, 0, 0);

    player_image.DrawRectangle(x_ + 12, y_ + 29, 3, 1, 206, 194, 177);
    player_image.DrawRectangle(x_ + 31, y_ + 29, 3, 1, 206, 194, 177);
    player_image.DrawRectangle(x_ + 16, y_ + 10, 1, 4, 206, 194, 177);
    player_image.DrawRectangle(x_ + 17, y_ + 8, 1, 7, 206, 194, 177);
    player_image.DrawRectangle(x_ + 18, y_ + 5, 1, 11, 206, 194, 177);
    player_image.DrawRectangle(x_ + 18, y_ + 5, 1, 11, 206, 194, 177);
    player_image.DrawRectangle(x_ + 19, y_ + 5, 1, 12, 206, 194, 177);
    player_image.DrawRectangle(x_ + 20, y_ + 5, 2, 3, 206, 194, 177);
    player_image.DrawRectangle(x_ + 22, y_ + 6, 2, 4, 206, 194, 177);
    player_image.DrawRectangle(x_ + 20, y_ + 10, 6, 2, 206, 194, 177);
    player_image.DrawRectangle(x_ + 20, y_ + 14, 1, 5, 206, 194, 177);
    player_image.DrawRectangle(x_ + 21, y_ + 15, 1, 1, 206, 194, 177);
    player_image.DrawRectangle(x_ + 22, y_ + 14, 2, 3, 206, 194, 177);
    player_image.DrawRectangle(x_ + 24, y_ + 15, 1, 1, 206, 194, 177);
    player_image.DrawRectangle(x_ + 25, y_ + 14, 1, 5, 206, 194, 177);
    player_image.DrawRectangle(x_ + 24, y_ + 5, 4, 3, 206, 194, 177);
    player_image.DrawRectangle(x_ + 26, y_ + 8, 3, 2, 206, 194, 177);
    player_image.DrawRectangle(x_ + 26, y_ + 10, 4, 4, 206, 194, 177);
    player_image.DrawRectangle(x_ + 26, y_ + 14, 1, 3, 206, 194, 177);
    player_image.DrawRectangle(x_ + 27, y_ + 14, 1, 2, 206, 194, 177);
    player_image.DrawRectangle(x_ + 28, y_ + 14, 1, 1, 206, 194, 177);

    player_image.DrawRectangle(x_ + 20, y_ + 13, 6, 1, 255, 255, 255);
    player_image.DrawRectangle(x_ + 21, y_ + 14, 1, 1, 255, 255, 255);
    player_image.DrawRectangle(x_ + 24, y_ + 14, 1, 1, 255, 255, 255);
    player_image.DrawRectangle(x_ + 20, y_ + 29, 6, 6, 255, 255, 255);
    player_image.DrawRectangle(x_ + 20, y_ + 19, 1, 10, 255, 255, 255);
    player_image.DrawRectangle(x_ + 21, y_ + 20, 1, 9, 255, 255, 255);
    player_image.DrawRectangle(x_ + 22, y_ + 19, 2, 2, 255, 255, 255);
    player_image.DrawRectangle(x_ + 22, y_ + 23, 2, 1, 255, 255, 255);
    player_image.DrawRectangle(x_ + 22, y_ + 26, 2, 1, 255, 255, 255);
    player_image.DrawRectangle(x_ + 24, y_ + 20, 1, 9, 255, 255, 255);
    player_image.DrawRectangle(x_ + 25, y_ + 19, 1, 10, 255, 255, 255);
  }

  void Move(const graphics::Image& image) {
    // std::cout << "hello";
  }
};

#endif

#ifndef PLAYER_PROJECTILE_H
#define PLAYER_PROJECTILE_H

class PlayerProjectile : public GameElement {
 public:
  PlayerProjectile() : GameElement(0, 0, 50, 50) {}
  PlayerProjectile(int x, int y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image& pprojectile_image) {
    pprojectile_image.DrawRectangle(x_ + 0, y_ + 1, 1, 4, 184, 137, 23);
    pprojectile_image.DrawRectangle(x_ + 1, y_ + 0, 1, 2, 184, 137, 23);
    pprojectile_image.DrawRectangle(x_ + 2, y_ + 0, 3, 1, 184, 137, 23);

    pprojectile_image.DrawRectangle(x_ + 2, y_ + 4, 3, 1, 244, 184, 41);
    pprojectile_image.DrawRectangle(x_ + 1, y_ + 3, 3, 1, 244, 184, 41);
    pprojectile_image.DrawRectangle(x_ + 1, y_ + 2, 4, 1, 244, 184, 41);
    pprojectile_image.DrawRectangle(x_ + 3, y_ + 1, 2, 1, 244, 184, 41);

    pprojectile_image.DrawRectangle(x_ + 1, y_ + 4, 1, 1, 255, 0, 0);
    pprojectile_image.DrawRectangle(x_ + 4, y_ + 3, 1, 1, 255, 0, 0);
    pprojectile_image.DrawRectangle(x_ + 2, y_ + 1, 1, 1, 255, 0, 0);
  }

  void Move(const graphics::Image& image) {
    y_ -= 3;
    if (IsOutOfBounds(image) == true) {
      is_active_ = false;
    }
  }
};

#endif
