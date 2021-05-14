#include <iostream>
#include <memory>
#include <iostream>
#include "cpputils/graphics/image.h"

#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

class GameElement {
 public:
  GameElement(const int x, const int y, const int width, const int height)
      : x_(x), y_(y), width_(width), height_(height) {}
  GameElement() : GameElement(0, 0, 50, 50) {}

  int GetX() const { return x_; }

  int GetY() const { return y_; }

  int GetWidth() const { return width_; }

  int GetHeight() const { return height_; }

  bool GetIsActive() const { return is_active_; }

  void SetX(int x) { x_ = x; }

  void SetY(int y) { y_ = y; }

  void SetIsActive(bool active) { is_active_ = active; }

  virtual void Draw(graphics::Image& image) = 0;

  virtual void Move(const graphics::Image& image) = 0;

  bool IntersectsWith(GameElement *gameElement) {
      return !(GetX() > gameElement->GetX() + gameElement->GetWidth() || gameElement->GetX() > GetX() + GetWidth() 
      || GetY() > gameElement->GetY() + gameElement->GetHeight() || gameElement->GetY() > GetY() + GetHeight());

/*    if ((gameElement->GetWidth() == 0) || (gameElement->GetWidth() == 0))
      return false;
    if ((width_ == 0) || (height_ == 0)) return false;
    if ((x_ > gameElement->GetX() + gameElement->GetWidth()) ||
        (x_ + width_ < gameElement->GetX()))
      return false;
    if ((y_ > gameElement->GetY() + gameElement->GetHeight()) ||
        (y_ + height_ < gameElement->GetY()))
      return false;
    return true;
*/  }

  bool IsOutOfBounds(const graphics::Image& image) {
    int image_width = image.GetWidth();
    int image_height = image.GetHeight();
    if ((x_ < 0) || (x_ > image_width)) {
      return true;
    }
    if (((x_ + width_) < 0) || ((x_ + width_) > image_width)) {
      return true;
    }
    if ((y_ < 0) || (y_ > image_height)) {
      return true;
    }
    if (((y_ + height_) < 0) || ((y_ + height_) > image_height)) {
      return true;
    }
    return false;
  }

 protected:
  int x_;
  int y_;
  int width_;
  int height_;
  bool is_active_ = true;
};

#endif
