#include "game.h"
#include <string>

Game::Game()
{
  flappy = Bird();
  score = 0;
  gameOver = false;
  gameInAction = false;
}

void Game::draw()
{
  flappy.draw();
  // Gravity effect
  if (gameInAction)
  {
    flappy.fall();
  }
  else
  {
    if (!gameOver)
      DrawTextEx(font, "FLAPPY BIRD", {5, 10}, 38, 2, BLACK);
  }

  if (flappy.getY() > GetScreenHeight() - 100)
  {
    gameOver = true;
    gameInAction = false;
  }

  if (gameOver)
  {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), {255, 0, 0, 200});
    std::string temp = "YOU SCORED: " + std::to_string(score);
    const char *lossMessage = temp.data();

    DrawTextEx(font, lossMessage, {80, float(GetScreenHeight() / 2) - 50}, 40, 2, BLACK);
    DrawTextEx(font, "PRESS ENTER TO PLAY AGAIN", {40, float(GetScreenHeight()/2 + 20)}, 24, 2, BLACK);
  }
}

void Game::handleInput()
{
  int keyPressed = GetKeyPressed();

  if (gameOver && keyPressed == KEY_ENTER)
  { // come back to this
    gameOver = false;
    reset();
  }

  if (keyPressed == KEY_SPACE)
  {
    flappy.jump();
    if (!gameInAction)
      gameInAction = true;
  }
}

void Game::reset(){
  score = 0;
  gameInAction = false;
  gameOver = false;
  flappy = Bird();
}