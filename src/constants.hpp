#pragma once

#include "raylib.h"
#include <vector>
using std::vector;

namespace consts
{
  const int screenWidth = 800;
  const int screenHeight = 700;

  const Image flappy = LoadImage("./img/flappy.png");
  const Texture2D flappy_tex = LoadTextureFromImage(flappy);
};
