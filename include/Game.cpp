#include "Game.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#include "Window.hpp"

#include <memory>
#include <SDL_render.h>
#include <utility>

Resources Game::resources;
  
void Game::Init(const char *title){
  Window::SetWindow(title, 640, 480);

  addPlayer("rectangle.bmp");
  addBall("rectangle.bmp");
}

void Game::Run() {
  bool isRunning = true;
  SDL_Event e;
  while (isRunning) {
    while(SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) isRunning = false;
    }
    Game::input(e);
    Game::update();
    Game::render();
  }
}

void Game::update() {
  for (auto&& entity : Game::resources.EntityList) {
    entity->update();
  }
}

void Game::addPlayer(const char* spriteSource) {
  std::shared_ptr<Player> player = std::make_shared<Player>(spriteSource, SDL_Rect {20, 160, 25, 200});

  Window::loadSprite(spriteSource);
  Game::resources.EntityList.insert(player);
  Game::resources.ListenerList.insert(player);
}

void Game::addBall(const char* spriteSource) {
  std::shared_ptr<Ball> ball = std::make_shared<Ball>(spriteSource, SDL_Rect {448, 192, 32, 32});

  Window::loadSprite(spriteSource);
  Game::resources.EntityList.insert(ball);
}

void Game::input(SDL_Event& e) {
  for (auto&& player : Game::resources.ListenerList) {
    player->inputListener(e);
  }
}

void Game::render() {
    SDL_RenderClear(Window::getRenderer());

    for (auto&& entity : Game::resources.EntityList) {
      SDL_Texture* tex = Window::getSprite(entity->getSourceName());
      SDL_RenderCopy(Window::getRenderer(), tex, nullptr, &entity->getCoordinates());
    }
  
    SDL_RenderPresent(Window::getRenderer());
}
