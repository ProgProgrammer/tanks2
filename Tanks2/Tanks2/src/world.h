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
    std::vector<IDrawable*> objects;
    std::vector<Brick*> bricks;
    Config* config;
    Levels levels;
    void calculate(sf::Event & event);
    void rendering();

public:
    World(int& num_level);
    ~World();
    void startLoop();
};