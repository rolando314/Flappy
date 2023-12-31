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
  int getX(){return x;}
  void incPipeSpeed(){pipeSpeedCounter += 1; if (pipeSpeed < 60 && pipeSpeedCounter % 3 == 0) pipeSpeed += 1;}

private:
  float x;
  int pipeSpeed;
  int pipeSpeedCounter = 1;
  const float width = 50;
  float upper_height;
  float lower_height;
};