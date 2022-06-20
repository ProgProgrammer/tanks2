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
    std::vector<IDrawable*> iDrawable;
    void calculate(sf::Event & event);
    void rendering();

public:
    World(std::vector<IDrawable*> idraw);
    void startLoop();
};