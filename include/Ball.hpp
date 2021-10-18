#pragma once

#include "Entity.hpp"

class Ball : public Entity {
public:
  Ball(const char* source, SDL_Rect&& coordinates);
  void checkOrientation();
  void update();
private:
  int speed = 1;
  int orientationX = -1;
  int orientationY = 1;
};
