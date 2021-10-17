#include "Window.hpp"

Window::Window(const char* title) {
  window   = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Window::loadSprite(const char* spriteSource) {
  SDL_Surface* tmpSurface = SDL_LoadBMP(spriteSource);
  spritePool[spriteSource] = SDL_CreateTextureFromSurface(renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);
}

SDL_Texture* Window::getSprite(const char* spriteSource) {
  return spritePool[spriteSource];
}
