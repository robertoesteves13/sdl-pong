#include "Player.hpp"
#include <iostream>

Player::Player(const char* source) : Entity(source){
}

void Player::inputListener(SDL_Event& e) {
  if (e.type == SDL_KEYDOWN) {
    switch (e.key.keysym.sym) {
      case SDLK_UP:
        update(-5);
        break;
      case SDLK_DOWN:
        update(5);
        break;
    }
  }
}
