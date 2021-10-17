#pragma once

#include <map>

#include "SDL.h"

class Window {
public:
  Window(const char* title);
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;

  SDL_Texture* getSprite(const char* spriteSource);
  void loadSprite(const char* spriteSource);
private:
  std::map<const char*, SDL_Texture*> spritePool;
};
