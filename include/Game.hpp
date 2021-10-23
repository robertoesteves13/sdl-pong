#pragma once
#include <SDL_render.h>
#include <map>
#include <memory>
#include <SDL.h>

#include "Listener.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include "Window.hpp"
#include "Resources.hpp"

class Game {
public:
  static void Init(const char* title, int sizeX, int sizeY);
  static void Run();
private:
  static Window window;

  static void addPlayer(const char* player);
  static void addBall(const char* player);

  static void input(SDL_Event& e);
  static void update();
  static void render();
  
  static Resources resources;
};
