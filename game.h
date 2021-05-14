#include <iostream>
#include <memory>
#include <string>
#include <vector>
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
    return opponentObjects_;
  }

  std::vector<std::unique_ptr<OpponentProjectile>>& GetOpponentProjectiles() {
    return opponentProjectile_;
  }

  std::vector<std::unique_ptr<PlayerProjectile>>& GetPlayerProjectiles() {
    return playerProjectile_;
  }

  Player& GetPlayer() { return player_; }

  void CreateOpponents() {
    std::unique_ptr<Opponent> opponent(new Opponent(0, 0));
    opponentObjects_.push_back(std::move(opponent));
  }

  void Init() {
    player_.SetX(10);
    player_.SetY(10);
    image_.AddMouseEventListener(*this);
    image_.AddAnimationEventListener(*this);
  }

  void LaunchProjectiles() {
    for (int i = 0; i < opponentObjects_.size(); i++) {
      std::unique_ptr<OpponentProjectile> functons_oponent =
          std::move(opponentObjects_[i]->LaunchProjectile());
      if (functons_oponent != nullptr) {
        opponentProjectile_.push_back(std::move(functons_oponent));
      }
    }
  }

  void UpdateScreen() {
    graphics::Color red(255, 0, 0);
    // image_.DrawRectangle(0, 0, image_.GetWidth(), image_.GetHeight(), red);
    for (int i = 0; i < opponentObjects_.size(); i++) {
      if (opponentObjects_[i]->GetIsActive() == true)
        opponentObjects_[i]->Draw(image_);
    }
    for (int i = 0; i < opponentProjectile_.size(); i++) {
      if (opponentProjectile_[i]->GetIsActive() == true)
        opponentProjectile_[i]->Draw(image_);
    }
    for (int i = 0; i < playerProjectile_.size(); i++) {
      if (playerProjectile_[i]->GetIsActive() == true)
        playerProjectile_[i]->Draw(image_);
    }
    if (player_.GetIsActive() == true) player_.Draw(image_);

    if (state == false) {
      std::string score_string = std::to_string(score);
      image_.DrawText(750, 550, score_string, 40, graphics::Color(0, 0, 0));
    } else {
      image_.DrawText(750, 550, "Game Over", 40, graphics::Color(0, 0, 0));
    }
  }

  void Start() { image_.ShowUntilClosed(); }

  void MoveGameElements() {
    for (int i = 0; i < opponentObjects_.size(); i++) {
      if (opponentObjects_[i]->GetIsActive() == true) {
        opponentObjects_[i]->Move(image_);
      }
    }
    for (int i = 0; i < opponentProjectile_.size(); i++) {
      if (opponentProjectile_[i]->GetIsActive() == true) {
        opponentProjectile_[i]->Move(image_);
      }
    }
    for (int i = 0; i < playerProjectile_.size(); i++) {
      if (playerProjectile_[i]->GetIsActive() == true) {
        playerProjectile_[i]->Move(image_);
      }
    }
  }

  void FilterIntersections() {
    state = false;
    for (int i = 0; i < opponentObjects_.size(); i++) {
      if (opponentObjects_[i]->GetIsActive() && player_.GetIsActive() &&
          player_.IntersectsWith(opponentObjects_[i].get())) {
        opponentObjects_[i]->SetIsActive(false);
        player_.SetIsActive(false);
        state = true;
      } else {
        for (int j = 0; j < playerProjectile_.size(); j++) {
          if (opponentObjects_[i]->GetIsActive() &&
              playerProjectile_[j]->GetIsActive() &&
              playerProjectile_[j]->IntersectsWith(opponentObjects_[i].get())) {
            opponentObjects_[i]->SetIsActive(false);
            playerProjectile_[j]->SetIsActive(false);
            score++;
          }
        }
      }
    }

    for (int i = 0; i < opponentProjectile_.size(); i++) {
      if (opponentProjectile_[i]->GetIsActive() && player_.GetIsActive() &&
          player_.IntersectsWith(opponentProjectile_[i].get())) {
        opponentProjectile_[i]->SetIsActive(false);
        player_.SetIsActive(false);
        state = true;
      }
    }

    if (player_.GetIsActive() == false) {
      score = 0;
    }
  }

  void RemoveInactive() {
    for (int i = (opponentObjects_.size() - 1); i > -1; i--) {
      if (opponentObjects_[i]->GetIsActive() == false) {
        opponentObjects_.erase(opponentObjects_.begin() + i);
      }
    }
    for (int i = (opponentProjectile_.size() - 1); i > -1; i--) {
      if (opponentProjectile_[i]->GetIsActive() == false) {
        opponentProjectile_.erase(opponentProjectile_.begin() + i);
      }
    }
    for (int i = (playerProjectile_.size() - 1); i > -1; i--) {
      if (playerProjectile_[i]->GetIsActive() == false) {
        playerProjectile_.erase(playerProjectile_.begin() + i);
      }
    }
  }

  void OnAnimationStep() {
    if (opponentObjects_.size() == 0) {
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
    if ((mouseEvent.GetMouseAction() == graphics::MouseAction::kPressed) ||
        (mouseEvent.GetMouseAction() == graphics::MouseAction::kDragged)) {
      int xUpdate = mouseEvent.GetX() - (player_.GetWidth() / 2);
      int yUpdate = mouseEvent.GetY() - (player_.GetHeight() / 2);
      int old_x = player_.GetX();
      int old_y = player_.GetY();

      player_.SetX(xUpdate);
      player_.SetY(yUpdate);

      if (player_.IsOutOfBounds(image_)) {
        player_.SetX(old_x);
        player_.SetY(old_y);
      }

      std::unique_ptr<PlayerProjectile> this_player_projectile(
          new PlayerProjectile(player_.GetX(), player_.GetY()));

      playerProjectile_.push_back(std::move(this_player_projectile));
    }
  }

 private:
  int score = 0;
  bool state;
  graphics::Image image_;
  std::vector<std::unique_ptr<Opponent>> opponentObjects_;
  std::vector<std::unique_ptr<OpponentProjectile>> opponentProjectile_;
  std::vector<std::unique_ptr<PlayerProjectile>> playerProjectile_;
  Player player_;
};
