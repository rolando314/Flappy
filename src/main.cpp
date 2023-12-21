#include "raylib.h"
#include "constants.hpp"

#include <iostream>

int main(void)
{
    InitWindow(consts::screenWidth, consts::screenHeight, "Pac-Man");
    SetTargetFPS(70);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawCircle(400, 300, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}