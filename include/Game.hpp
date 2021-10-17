#pragma once
#include <SDL_render.h>
#include <map>
#include <memory>
#include <forward_list>
#include <SDL.h>

#include "Listener.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include "Window.hpp"

class Game {
public:
  Game(const char* title);
  
  void addPlayer(const char* player);
  void update(SDL_Event& e);
  void render();
  void run();
private:
  Window window;

  std::forward_list<std::shared_ptr<Listener>> listenerList;
  std::forward_list<std::shared_ptr<Entity>> entityList;
};
