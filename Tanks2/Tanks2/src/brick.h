#pragma once
#include "iDrawable.h"

class Brick : public IDrawable
{
public:
    void calculate(sf::Event& event) override;
    void draw() override;
};