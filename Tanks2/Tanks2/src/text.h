#pragma once
#include "i_drawable.h"

class Text : public IDrawable
{
  public:
    void calculate(sf::Event& event) override;
    void draw() override;
};