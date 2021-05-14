#include <iostream>
#include "game.h"

int main() {
  Game game1(200, 200);
  game1.Init();
  game1.UpdateScreen();
  game1.Start();
};
