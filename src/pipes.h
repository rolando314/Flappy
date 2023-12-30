#pragma once
#include "raylib.h"
#include <random>

class Pipes
{
public:
  Pipes(int x);
  ~Pipes();
  Rectangle upper;
  Rectangle lower;
  void draw();

private:
  float x;
  int pipeSpeed;
  const float width = 50;
  float upper_height;
  float lower_height;
};