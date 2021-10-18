#include "Entity.hpp"
#include "Game.hpp"

#include <utility>
#include <memory>
#include <SDL_keycode.h>
#include <SDL_render.h>

Entity::Entity(const char *source, SDL_Rect&& coordinates)
    : spriteSource(source) {
  entityCoordinates = std::move(coordinates);
}

const char *Entity::getSourceName() { return this->spriteSource; }

SDL_Rect& Entity::getCoordinates() { return entityCoordinates; }

SDL_Rect *Entity::getSize() { return size; }
