#include "Player.hpp"
#include <iostream>

Player::Player(const char* source, SDL_Rect&& coordinates) : Entity(source, std::move(coordinates)){
}

void Player::inputListener(SDL_Event& e) {
  if (e.type == SDL_KEYDOWN) {
    switch (e.key.keysym.sym) {
      case SDLK_UP:
        updateHeight -= 5;
        break;
      case SDLK_DOWN:
        updateHeight += 5;
        break;
    }
  }
}

void Player::update() {
  if (entityCoordinates.y + updateHeight >= 0 && entityCoordinates.y + updateHeight <= 480 - this->entityCoordinates.h) {
    entityCoordinates.y += updateHeight;
  }

  updateHeight = 0;
}

