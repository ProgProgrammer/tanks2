#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "brick.h"
#include "bullet.h"
#include "text.h"
#include "tank.h"
#include "config.h"

sf::RenderWindow window(sf::VideoMode(600, 600), "TestProgram");

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