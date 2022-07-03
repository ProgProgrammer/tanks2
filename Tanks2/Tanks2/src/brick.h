#pragma once
#include "iDrawable.h"
#include "level.h"

class Brick : public IDrawable, virtual public Level
{
public:
    void calculate(sf::Event& event) override;
    void draw() override;
};