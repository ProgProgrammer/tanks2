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
    void calculate(sf::Event & event);
    void rendering();

public:
    World();
    ~World();
    void startLoop();
};