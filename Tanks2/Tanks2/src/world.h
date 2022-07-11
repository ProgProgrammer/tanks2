#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "brick.h"
#include "bullet.h"
#include "text.h"
#include "tank.h"

class World
{
private:
    sf::RenderWindow m_window;
    std::vector<IDrawable*> m_objects;
    std::vector<Brick*> m_bricks;
    Config* m_config;
    Levels m_levels;
    void calculate(sf::Event & event);
    void rendering();

public:
    World();
    ~World();
    void startLoop();
};