#pragma once

#include "Entity.hpp"

#include <SDL.h>
#include <SDL_render.h>
#include <forward_list>
#include <tuple>

class Entity {
public:
  Entity(const char* source, SDL_Rect &&coordinates);

  const char* getSourceName();
  virtual void update() = 0;
  SDL_Rect& getCoordinates();
  SDL_Rect* getSize();
protected:
  const char* spriteSource;

  SDL_Rect entityCoordinates;
  SDL_Rect* size;
};
