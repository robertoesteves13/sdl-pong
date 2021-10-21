#pragma once
#include "Entity.hpp"
#include "Listener.hpp"
#include <memory>
#include <unordered_set>

struct Resources {
  std::unordered_set<std::shared_ptr<Listener>> ListenerList;
  std::unordered_set<std::shared_ptr<Entity>> EntityList;
};
