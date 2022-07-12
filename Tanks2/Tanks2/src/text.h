#pragma once
#include "iDrawable.h"

class Text : public IDrawable
{
  public:
    void calculate(sf::Event& event) override;
    void draw() override;
};