#include "bird.h"

Bird::Bird()
{
  y = 250;
}

void Bird::draw()
{
  DrawTextureEx(flappy_img, {float(x - 50), float(y - 40)}, angle, 0.1, WHITE);
}

void Bird::jump()
{
  angle = -10;
  y -= 30;
  if (t.eventTriggered(0.05))
    y -= 50;
}

void Bird::fall()
{
  y += 4;
  rotateDown();
}

void Bird::rotateDown()
{
  if (angle < 90) angle += 0.5;
}