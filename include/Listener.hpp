#pragma once

#include "SDL.h"

class Listener {
public:
  virtual void inputListener(SDL_Event &e) = 0;
};
