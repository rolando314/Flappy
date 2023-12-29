#pragma once
#include "raylib.h"
#include "bird.h"

class Game
{
public:
  Game();
  int score;
  bool gameOver;
  void handleInput();
  void reset();
  void draw();

private:
  Bird flappy;
  bool gameInAction;
  Font font = LoadFontEx("src/fonts/press_start.ttf", 64, 0, 0);
  void restart();
};