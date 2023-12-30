#pragma once
#include "raylib.h"
#include "time.h"

class Bird
{
public:
  Bird();
  void jump();
  void fall();
  void draw();
  int getY(){return y;}
  Texture2D getTexture(){return flappy_img;}

private:
  int x = 350;
  int y;
  float angle = 0.0;
  Time t;
  Texture2D flappy_img =  LoadTexture("img/flappy.png");
  void rotateDown();
};