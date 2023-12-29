#include "game.h"

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
  if (gameInAction && !gameOver)
  {
    flappy.fall();
  }
  else
  {
    DrawTextEx(font, "FLAPPY BIRD", {5, 10}, 38, 2, BLACK);
  }

  if (flappy.getY() > GetScreenHeight() - 100){
    gameOver = true;
    gameInAction = false;
  }

  if (gameOver){
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), {255, 0, 0, 200});
  }

}

void Game::handleInput()
{
  int keyPressed = GetKeyPressed();

  if (gameOver && keyPressed != 0)
  { // come back to this
    gameOver = false;
    // reset();
  }

  if (keyPressed == KEY_SPACE)
  {
    flappy.jump();
    if (!gameInAction)
      gameInAction = true;
  }
}