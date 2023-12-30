#pragma once
#include "raylib.h"
#include "bird.h"
#include <random>

class Pipes
{
public:
  Pipes(int x);
  ~Pipes();
  Rectangle upper;
  Rectangle lower;
  void draw();
  bool checkPipeCollision(Bird flappy);

private:
  float x;
  int pipeSpeed;
  const float width = 50;
  float upper_height;
  float lower_height;
};