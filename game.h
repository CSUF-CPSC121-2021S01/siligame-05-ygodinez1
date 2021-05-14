#include <iostream>
#include <vector>
#include <memory>
#include "cpputils/graphics/image.h"
#include "cpputils/graphics/image_event.h"
#include "game_element.h"
#include "player.h"

class Game : public graphics::AnimationEventListener,
             graphics::MouseEventListener {
 public:
  Game() : image_(800, 600) {}
  Game(int width, int height) : image_(width, height) {}

  int GetScore() { return score; }

  bool HasLost() { return state; }

  graphics::Image& GetGameScreen() { return image_; }

  std::vector<std::unique_ptr<Opponent>>& GetOpponents() { 
      return std::move(opponentObjects_); }

  std::vector<std::unique_ptr<OpponentProjectile>>& GetOpponentProjectiles() {
    return std::move(opponentProjectile_);
  }

  std::vector<std::unique_ptr<PlayerProjectile>>& GetPlayerProjectiles() {
    return std::move(playerProjectile_);
  }

  Player& GetPlayer() { return player_; }

  void CreateOpponents() {
    std::unique_ptr<Opponent> opponent(new Opponent(0,0));
    opponentObjects_.push_back(opponent);
  }

  void Init() {
    player_.SetX(10);
    player_.SetY(10);
    image_.AddMouseEventListener(*this);
    image_.AddAnimationEventListener(*this);
  }

  void LaunchProjectiles() {
      for(int i = 0; i < opponentObjects_.size(); i++) {
          std::unique_ptr<OpponentProjectile> functons_oponent 
          = std::move(LaunchProjectile(opponentObjects_[i])) {
          if(functons_oponent != nullptr) {
              opponentProjectile_.push_back(functons_oponent);
          }
          }
      }
  }

  void UpdateScreen() {
    graphics::Color red(255, 0, 0);
    // image_.DrawRectangle(0, 0, image_.GetWidth(), image_.GetHeight(), red);

    for (int i = 0; i < opponentObjects_.size(); i++) {
      Opponent this_opponent = *opponentObjects_[i];
      if (opponentObjects_[i].GetIsActive() == true)
        opponentObjects_[i].Draw(image_);
    }
    for (int i = 0; i < opponentProjectile_.size(); i++) {
      OpponentProjectile this_opponent_projectile = *opponentProjectile_[i];
      if (this_opponent_projectile.GetIsActive() == true)
        this_opponent_projectile.Draw(image_);
    }
    for (int i = 0; i < playerProjectile_.size(); i++) {
      PlayerProjectile this_player_projectile = *playerProjectile_[i];
      if (this_player_projectile.GetIsActive() == true)
        this_player_projectile.Draw(image_);
    }
    if (player_.GetIsActive() == true) player_.Draw(image_);
  }

  void Start() { image_.ShowUntilClosed(); }

  void MoveGameElements() {
    for (int i = 0; i < opponentObjects_.size(); i++) {
      Opponent this_opponent = *opponentObjects_[i];
      if(this_opponent.GetIsActive() == true) {
            this_opponent.Move(image_);
      }
    }

    for (int i = 0; i < opponentProjectile_.size(); i++) {
      OpponentProjectile this_opponent_projectile = *opponentProjectile_[i];
      if(this_opponent_projectile.GetIsActive() == true) {
            this_opponent_projectile.Move(image_);
      }
    }
    for (int i = 0; i < playerProjectile_.size(); i++) {
      PlayerProjectile this_player_projectile = *playerProjectile_[i];
        if(this_player_projectile.GetIsActive() == true) {
            this_player_projectile.Move(image_);
      }    
    }
  }

  void FilterIntersections() {
    for (int i = 0; i < opponentObjects_.size(); i++) {
      Opponent this_opponent = opponentObjects_[i].get();
      if(player_.GetIsActive() && this_opponent.GetIsActive()) {
        if (player_.IntersectsWith(this_opponent)) {
            player_.SetIsActive(false);
            this_opponent.SetIsActive(false);
            state = false;
        }
      }
    }

    for (int i = 0; i < playerProjectile_.size(); i++) {
      PlayerProjectile this_player_projectile = *playerProjectile_[i];
      for (int j = 0; j < opponentObjects_.size(); j++) {
        Opponent this_opponent = *opponentObjects_[j];
        if(this_player_projectile.GetIsActive() && this_opponent.GetIsActive()) {
            if (this_player_projectile.IntersectsWith(this_opponent)) {
            this_player_projectile.SetIsActive(false);
            this_opponent.SetIsActive(false);
            state = false;
            }
        }
      }
    }

    for (int i = 0; i < opponentProjectile_.size(); i++) {
      OpponentProjectile this_opponent_projectile = *opponentProjectile_[i];
      if(this_player_projectile.GetIsActive() && player_.GetIsActive())  {
        if (this_opponent_projectile.IntersectsWith(player_)) {
            this_opponent_projectile.SetIsActive(false);
            player_.SetIsActive(false);
            score++;
        }
      }
    }
  }

  void RemoveInactive() {
      for(int i = 0; i < opponentObjects_.size(); i++) {
          Opponent this_opponent_objct = *opponentObjects_[i];
          if(this_opponent_objct.GetIsActive(() == false) {
              opponentObjects_.erase(numbers.begin() + i);
          }
      }
      for(int i = 0; i < opponentProjectile_.size(); i++) {
          OpponentProjectile this_opponent_projectile = *opponentProjectile_[i];
          if(this_opponent_projectile.GetIsActive(() == false) {
              opponentProjectile_.erase(numbers.begin() + i);
          }
      }
      for(int i = playerProjectile_.size() - 1 ; i >= 0; i++) {
          PlayerProjectile this_player_projectile = *playerProjectile_[i];
          if(this_player_projectile.GetIsActive(() == false) {
              this_player_projectile.erase(numbers.begin() + i);
          }
      }
  }

  void OnAnimationStep() {
    if(opponentObjects_.size() == 0) {
        CreateOpponents();
    }
    MoveGameElements();
    LaunchProjectiles();
    FilterIntersections();
    RemoveInactive();
    UpdateScreen();
    image_.Flush();
  }

  void OnMouseEvent(const graphics::MouseEvent& mouseEvent) {
    if ((mouseEvent.GetMouseAction() == graphics::MouseAction::kMoved) ||
        (mouseEvent.GetMouseAction() == graphics::MouseAction::kDragged)) {
      std::unique_ptr<PlayerProjectile> this_player_projectile;
      playerProjectile_.push_back(std::move(playerProjectile_));
      int xUpdate = (mouseEvent.GetX() - (player_.GetWidth() / 2));
      int yUpdate = (mouseEvent.GetY() - (player_.GetHeight() / 2));

      if (!((xUpdate < 0) || (xUpdate > image_.GetWidth()))) {
        if (!((yUpdate < 0) || (xUpdate > image_.GetHeight()))) {
          player_.SetX(xUpdate);
          player_.SetY(yUpdate);
        }
      }
    }
  }

 private:
  int score;
  bool state;
  graphics::Image image_;
  std::vector<std::unique_ptr<Opponent>> opponentObjects_;
  std::vector<std::unique_ptr<OpponentProjectile>> opponentProjectile_;
  std::vector<std::unique_ptr<PlayerProjectile>> playerProjectile_;
  Player player_;
};
