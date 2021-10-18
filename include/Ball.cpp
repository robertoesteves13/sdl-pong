#include "Ball.hpp"

void Ball::update() {
  entityCoordinates.x -= 3;
}

Ball::Ball(const char *sourceName, SDL_Rect &&rectangle)
    : Entity(sourceName, std::move(rectangle)){};
