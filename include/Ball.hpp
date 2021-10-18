#pragma once

#include "Entity.hpp"

class Ball : public Entity {
public:
  Ball(const char* source, SDL_Rect&& coordinates);
  void update();
private:
  int time = 0;
};
