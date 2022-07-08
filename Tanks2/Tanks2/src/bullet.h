#pragma once
#include "iDrawable.h"

class Bullet : public IDrawable
{
public:
    void calculate(sf::Event& event) override;
    void draw() override;
};