#pragma once

#include <map>

#include "SDL.h"

struct WindowSize {
  int x;
  int y;
};

class Window {
public:
  static void SetWindow(const char* title, int sizeX, int sizeY);

  static SDL_Renderer* getRenderer() { return renderer; };
  static WindowSize getWindowSize() { return Size; };

  static SDL_Texture* getSprite(const char* spriteSource);
  static void loadSprite(const char* spriteSource);
private:
  static WindowSize Size;
  
  static SDL_Window* window;
  static SDL_Renderer* renderer;
  static std::map<const char*, SDL_Texture*> spritePool;
};
