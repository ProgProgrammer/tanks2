#pragma once
#include "iDrawable.h"

class Tank : public IDrawable
{
public:
    void calculate(sf::Event& event) override;
    void draw() override;
};