#include "raylib.h"
#include <iostream>
#include "game.h"

int main()
{
  InitWindow(700, 550, "Flappy Bird");
  SetTargetFPS(70);

  Game game;

  while (!WindowShouldClose())
  {

    game.handleInput();

    BeginDrawing();
    ClearBackground({56, 191, 232, 255});

    // Drawing scenery
    Color VERY_LIGHT_GRAY = {240, 244, 245, 250}; // not quite white
    DrawRectangle(0, 500, 700, 200, GREEN);

    DrawRectangle(100, 100, 80, 40, VERY_LIGHT_GRAY);
    DrawRectangle(150, 120, 100, 50, VERY_LIGHT_GRAY);
    DrawRectangle(200, 90, 70, 30, VERY_LIGHT_GRAY);
    DrawRectangle(250, 110, 90, 40, VERY_LIGHT_GRAY);

    game.draw();

    EndDrawing();
  }
  CloseWindow();
}
