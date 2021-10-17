#pragma once

#include "Entity.hpp"
#include "Listener.hpp"

class Player : public Entity, public Listener {
public:
  Player(const char* source);

  void inputListener(SDL_Event& e) override;
};
