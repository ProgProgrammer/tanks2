#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "brick.h"
#include "bullet.h"
#include "text.h"
#include "tank.h"

class World
{
private:
    std::vector<IDrawable*> objects;
    void calculate(sf::Event & event);
    void rendering();

public:
    World();
    ~World();
    void startLoop();
};