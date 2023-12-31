#include "pipes.h"

Pipes::Pipes(int x)
{
  this->x = x;
  upper_height = (float)GetRandomValue(20, 250);
  lower_height = GetScreenHeight() - upper_height - 50;
  pipeSpeed = 1;
}

Pipes::~Pipes() {}

void Pipes::draw()
{
  x -= pipeSpeed;
  upper = {x, 0, width, upper_height};
  lower = {x, upper_height + 180, width, lower_height};

  // Upper pipe
  DrawRectanglePro(upper, {0, 0}, 0, {2, 15, 196, 255});

  // Lower pipe
  DrawRectanglePro(lower, {0, 0}, 0, {2, 15, 196, 255});
}

bool Pipes::checkPipeCollision(Bird flappy)
{
  return (CheckCollisionRecs((Rectangle){static_cast<float>(350), static_cast<float>(flappy.getY()), 
  static_cast<float>(50), static_cast<float>(50)}, upper))
   
  || 
  
  (CheckCollisionRecs((Rectangle){static_cast<float>(350), static_cast<float>(flappy.getY()), 
  static_cast<float>(50), static_cast<float>(50)}, lower));
}