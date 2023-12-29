#pragma once
#include "raylib.h"

struct Time
{
  double lastUpdate = 0;

  bool eventTriggered(double interval)
  {
    double rightNow = GetTime();
    if (rightNow - lastUpdate >= interval)
    {
      lastUpdate = rightNow;
      return true;
    }
    return false;
  }
};