#include "Window.hpp"

WindowSize Window::Size;
SDL_Window* Window::window;
SDL_Renderer* Window::renderer;
std::map<const char*, SDL_Texture*> Window::spritePool;

void Window::SetWindow(const char* title, int sizeX, int sizeY) {
  window   = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sizeX, sizeY, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  Window::Size = {sizeX, sizeY};
}

void Window::loadSprite(const char* spriteSource) {
  SDL_Surface* tmpSurface = SDL_LoadBMP(spriteSource);
  spritePool[spriteSource] = SDL_CreateTextureFromSurface(renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);
}

SDL_Texture* Window::getSprite(const char* spriteSource) {
  return spritePool[spriteSource];
}
