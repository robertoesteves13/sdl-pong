#pragma once

#include "Entity.hpp"
#include "Listener.hpp"

class Player : public Entity, public Listener {
public:
  Player(const char* source, SDL_Rect&& coordinates);

  void update() override;
  void inputListener(SDL_Event& e) override;
private:
  int updateHeight = 0;
};
