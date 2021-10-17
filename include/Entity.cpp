#include "Entity.hpp"
#include "Game.hpp"

#include <SDL_keycode.h>
#include <SDL_render.h>

Entity::Entity(const char* source) : spriteSource(source) {
}

const char* Entity::getSourceName() {
  return this->spriteSource;
}

void Entity::update(int height) {
  if (position.y + height >= 0 && position.y + height <= 480 - this->position.h) {
    position.y += height;
  }
}

SDL_Rect* Entity::getPosition() {
  return &position;
}

SDL_Rect* Entity::getSize() {
  return size;
}
