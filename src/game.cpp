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
  if (gameInAction)
  {
    pipes->draw();
    nextPipes->draw();
  }

  // Gravity effect
  if (gameInAction)
    flappy.fall();

  // Title message
  else
    drawTitle();

  // Checking floor and pipe collision
  checkCollisions();

  // Checking if flappy passes a pipe
  checkPassedPipe();

  // Game-over message
  gameOverScreen();
}

void Game::handleInput()
{
  int keyPressed = GetKeyPressed();

  if (gameOver && keyPressed == KEY_ENTER)
  { // come back to this
    gameOver = false;
    reset();
  }

  if (keyPressed == KEY_SPACE && !gameOver)
  {
    flappy.jump();
    if (!gameInAction)
      gameInAction = true;
  }
}

void Game::reset()
{
  *this = Game();
}

void Game::drawTitle()
{
  if (!gameOver)
  {
    DrawTextEx(font, "FLAPPY BIRD", {5, 10}, 38, 2, BLACK);
  }
}

void Game::checkCollisions()
{
  // Floor collision & pipe collision
  if ((flappy.getY() > GetScreenHeight() - 100) || pipes->checkPipeCollision(flappy))
  {
    gameOver = true;
    gameInAction = false;
  }
}

void Game::gameOverScreen()
{
  if (gameOver)
  {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), {255, 0, 0, 200});
    std::string temp = "YOU SCORED: " + std::to_string(score);
    const char *lossMessage = temp.data();

    DrawTextEx(font, lossMessage, {80, float(GetScreenHeight() / 2) - 50}, 40, 2, BLACK);
    DrawTextEx(font, "PRESS ENTER TO PLAY AGAIN", {40, float(GetScreenHeight() / 2 + 20)}, 24, 2, BLACK);
  }
}

void Game::checkPassedPipe()
{
  if (!gameOver && gameInAction)
  {
    if (flappy.getX() > (pipes->getX() + 50))
    {
      score += 1;
      if (flappy.getX() > pipes->getX() + 400)
      {
        score -= 350;
        delete pipes;
        pipes = nextPipes;
        nextPipes = new Pipes(800);
      }
    }
  }
}