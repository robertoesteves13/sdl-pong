#include "Game.hpp"
#include "Player.hpp"
#include "Ball.hpp"

#include <memory>
#include <SDL_render.h>

Game::Game(const char *title) : window(title){
  addPlayer("rectangle.bmp");
  addBall("rectangle.bmp");
}

void Game::run() {
  bool isRunning = true;
  SDL_Event e;
  while (isRunning) {
    while(SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) isRunning = false;
    }
    this->input(e);
    this->update();
    this->render();
  }
}

void Game::update() {
  for (auto&& entity : entityList) {
    entity->update();
  }
}

void Game::addPlayer(const char* spriteSource) {
  std::shared_ptr<Player> player = std::make_shared<Player>(spriteSource, SDL_Rect {20, 160, 25, 200});

  window.loadSprite(spriteSource);
  entityList.push_front(player);
  listenerList.push_front(player);
}

void Game::addBall(const char* spriteSource) {
  std::shared_ptr<Ball> ball = std::make_shared<Ball>(spriteSource, SDL_Rect {448, 192, 32, 32});

  window.loadSprite(spriteSource);
  entityList.push_front(ball);
}

void Game::input(SDL_Event& e) {
  for (auto&& player : listenerList) {
    player->inputListener(e);
  }
}

void Game::render() {
    SDL_RenderClear(window.renderer);

    for (auto&& entity : entityList) {
      SDL_Texture* tex = window.getSprite(entity->getSourceName());
      SDL_RenderCopy(window.renderer, tex, nullptr, &entity->getCoordinates());
    }
  
    SDL_RenderPresent(window.renderer);
}
