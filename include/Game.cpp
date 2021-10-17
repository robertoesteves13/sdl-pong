#include "Game.hpp"
#include "Player.hpp"

#include <memory>
#include <SDL_render.h>

Game::Game(const char *title) : window(title){
  addPlayer("rectangle.bmp");
}

void Game::run() {
  bool isRunning = true;
  SDL_Event e;
  while (isRunning) {
    while(SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) isRunning = false;
    }
    this->update(e);
    this->render();
  }
}

void Game::addPlayer(const char* spriteSource) {
  std::shared_ptr<Player> player = std::make_shared<Player>(spriteSource);

  window.loadSprite(spriteSource);
  entityList.push_front(player);
  listenerList.push_front(player);
}

void Game::update(SDL_Event& e) {
  for (auto&& entity : listenerList) {
    entity->inputListener(e);
  }
}

void Game::render() {
    SDL_RenderClear(window.renderer);

    for (auto&& entity : entityList) {
      SDL_Texture* tex = window.getSprite(entity->getSourceName());
      SDL_RenderCopy(window.renderer, tex, nullptr, entity->getPosition());
    }
  
    SDL_RenderPresent(window.renderer);
}
