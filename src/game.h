#pragma once
#include "raylib.h"
#include "bird.h"
#include "pipes.h"
#include <string>

class Game
{
public:
  Game();
  int score;
  bool gameOver;
  void handleInput();
  void draw();

private:
  Bird flappy;
  Pipes *pipes = new Pipes(800);
  Pipes *nextPipes = new Pipes(1200);
  bool gameInAction;
  Font font = LoadFontEx("src/fonts/press_start.ttf", 64, 0, 0);
  void restart();
  void reset();
  void drawTitle();
  void displayScore();
  void checkCollisions();
  void gameOverScreen();
  void checkPassedPipe();
  bool shouldIncScore;
};