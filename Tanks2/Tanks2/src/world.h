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
    std::vector<IDrawable*> m_objects;
    std::vector<Brick*> m_bricks;
    Config* m_config;
    Levels m_levels;
    int m_num_level;
    void calculate(sf::Event & event);
    void rendering();

public:
    World();
    ~World();
    void startLoop();
};