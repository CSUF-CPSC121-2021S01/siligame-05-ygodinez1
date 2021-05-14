#include <iostream>
#include <vector>
#include <memory>
#include <string>
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
      return opponentObjects_; }

  std::vector<std::unique_ptr<OpponentProjectile>>& GetOpponentProjectiles() {
    return opponentProjectile_;
  }

  std::vector<std::unique_ptr<PlayerProjectile>>& GetPlayerProjectiles() {
    return playerProjectile_;
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
          = std::move(opponentObjects_[i]->LaunchProjectile());
          if(functons_oponent != nullptr) {
              opponentProjectile_.push_back(functons_oponent);
          }
      }
  }

  void UpdateScreen() {
    graphics::Color red(255, 0, 0);
    // image_.DrawRectangle(0, 0, image_.GetWidth(), image_.GetHeight(), red);
    for (int i = 0; i < opponentObjects_.size(); i++) {
      std::unique_ptr<Opponent> this_opponent = std::move(opponentObjects_[i]);
      if (this_opponent.get()->GetIsActive() == true)
        opponentObjects_[i]->Draw(image_);
    }
    for (int i = 0; i < opponentProjectile_.size(); i++) {
      std::unique_ptr<OpponentProjectile> this_opponent_projectile 
      = std::move(opponentProjectile_[i]);
      if (this_opponent_projectile->GetIsActive() == true)
        this_opponent_projectile->Draw(image_);
    }
    for (int i = 0; i < playerProjectile_.size(); i++) {
      std::unique_ptr<PlayerProjectile> this_player_projectile 
      = std::move(playerProjectile_[i]);
      if (this_player_projectile->GetIsActive() == true)
        this_player_projectile->Draw(image_);
    }
    if (player_.GetIsActive() == true) player_.Draw(image_);

    if(state == true) {
        std::string score_string = std::to_string(score);
        image_.DrawText(750,550,score_string, 40, graphics::Color(0,0,0));
    } else {
        image_.DrawText(750,550,"Game Over", 40, graphics::Color(0,0,0));
    }
  }

  void Start() { image_.ShowUntilClosed(); }

  void MoveGameElements() {
    for (int i = 0; i < opponentObjects_.size(); i++) {
      std::unique_ptr<Opponent> this_opponent = std::move(opponentObjects_[i]);
      if(this_opponent->GetIsActive() == true) {
            this_opponent->Move(image_);
      }
    }

    for (int i = 0; i < opponentProjectile_.size(); i++) {
      std::unique_ptr<OpponentProjectile> this_opponent_projectile 
      = std::move(opponentProjectile_[i]);
      if(this_opponent_projectile->GetIsActive() == true) {
            this_opponent_projectile->Move(image_);
      }
    }
    for (int i = 0; i < playerProjectile_.size(); i++) {
      std::unique_ptr<PlayerProjectile> this_player_projectile 
      = std::move(playerProjectile_[i]);
        if(this_player_projectile->GetIsActive() == true) {
            this_player_projectile->Move(image_);
      }    
    }
  }

  void FilterIntersections() {
    for (int i = 0; i < opponentObjects_.size(); i++) {
      std::unique_ptr<Opponent> this_opponent = std::move(opponentObjects_[i]);
      if(player_.GetIsActive() && this_opponent.get()->GetIsActive()) {
        if (player_.IntersectsWith(this_opponent.get())) {
            player_.SetIsActive(false);
            this_opponent->SetIsActive(false);
            state = false;
        }
      }
    }

    for (int i = 0; i < playerProjectile_.size(); i++) {
      std::unique_ptr<PlayerProjectile> this_player_projectile 
      = std::move(playerProjectile_[i]);
      for (int j = 0; j < opponentObjects_.size(); j++) {
        std::unique_ptr<Opponent> this_opponent = std::move(opponentObjects_[j]);
        if(this_player_projectile->GetIsActive() && this_opponent->GetIsActive()) {
            if (this_player_projectile->IntersectsWith(this_opponent.get())) {
            this_player_projectile->SetIsActive(false);
            this_opponent->SetIsActive(false);
            state = false;
            }
        }
      }
    }

    for (int i = 0; i < opponentProjectile_.size(); i++) {
      std::unique_ptr<OpponentProjectile> this_opponent_projectile 
      = std::move(opponentProjectile_[i]);
      if(this_opponent_projectile->GetIsActive() && player_.GetIsActive())  {
        if (this_opponent_projectile->IntersectsWith(&player_)) {
            this_opponent_projectile->SetIsActive(false);
            player_.SetIsActive(false);
            score++;
        }
      }
    }
  }

  void RemoveInactive() {
      for(int i = 0; i < opponentObjects_.size(); i++) {
          std::unique_ptr<Opponent> this_opponent = std::move(opponentObjects_[i]);
          if(this_opponent->GetIsActive() == false) {
              opponentObjects_.erase(opponentObjects_.begin() + i);
          }
      }
      for(int i = 0; i < opponentProjectile_.size(); i++) {
          std::unique_ptr<OpponentProjectile> this_opponent_projectile 
      = std::move(opponentProjectile_[i]);

          if(this_opponent_projectile->GetIsActive() == false) {
              opponentProjectile_.erase(opponentProjectile_.begin() + i);
          }
      }
      for(int i = playerProjectile_.size() - 1 ; i >= 0; i++) {
          PlayerProjectile this_player_projectile = *playerProjectile_[i];
          if(this_player_projectile.GetIsActive() == false) {
              playerProjectile_.erase(playerProjectile_.begin() + i);
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
      int xUpdate = (mouseEvent.GetX() - (player_.GetWidth() / 2));
      int yUpdate = (mouseEvent.GetY() - (player_.GetHeight() / 2));
      int old_x = player_.GetX();
      int old_y = player_.GetY();

      player_.SetX(xUpdate);
      player_.SetY(yUpdate);

      if (player_.IsOutOfBounds(image_)) {
          player_.SetX(xUpdate);
          player_.SetY(yUpdate);
        }
      
      std::unique_ptr<PlayerProjectile> 
      this_player_projectile(new PlayerProjectile(player_.GetX(), player_.GetY()))

      playerProjectile_.push_back();
   //   std::unique_ptr<PlayerProjectile> 
   //   this_player_projectile(new PlayerProjectile(player_.GetX(), player_.GetY()));
    //  playerProjectile_.push_back(this_player_projectile);
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
