#include "Ball.hpp"
#include "Window.hpp"

Ball::Ball(const char *sourceName, SDL_Rect &&rectangle)
    : Entity(sourceName, std::move(rectangle)){};

void Ball::update() {
  checkOrientation();
  entityCoordinates.x += speed * orientationX * 3;
  entityCoordinates.y += speed * orientationY;
}

void Ball::checkOrientation() {
  if (entityCoordinates.x <= 0) {
    orientationX = 1;
  }
  else if (entityCoordinates.x >= Window::getWindowSize().x - entityCoordinates.w) {
    orientationX = -1;
  }

  if (entityCoordinates.y <= 0) {
    orientationY = 1;
  }
  else if (entityCoordinates.y >= Window::getWindowSize().y - entityCoordinates.h) {
    orientationY = -1;
  }
}
