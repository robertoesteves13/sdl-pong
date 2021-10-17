#pragma once

#include "Entity.hpp"

#include <SDL.h>
#include <SDL_render.h>
#include <forward_list>
#include <tuple>

class Entity {
public:
  Entity(const char* source);

  const char* getSourceName();
  void update(int height);
  SDL_Rect* getPosition();
  SDL_Rect* getSize();
private:
  const char* spriteSource;

  SDL_Rect position = {16, 16, 32, 200};
  SDL_Rect* size;
};
