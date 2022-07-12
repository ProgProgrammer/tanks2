#pragma once
#include "brick.h"
#include "bullet.h"
#include "tank.h"
#include "text.h"
#include <SFML/Graphics.hpp>
#include <vector>

class World
{
  private:
    sf::RenderWindow m_window;
    std::vector<IDrawable*> m_objects;
    std::vector<Brick*> m_bricks;
    Config* m_config;
    Levels m_levels;
    void calculate(sf::Event& event);
    void rendering();

  public:
    World();
    ~World();
    void startLoop();
};