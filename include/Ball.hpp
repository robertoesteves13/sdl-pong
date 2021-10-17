#pragma once

#include "Entity.hpp"

class Ball : public Entity {
public:
  Ball(const char* sourceName) : Entity(sourceName) {};
};
