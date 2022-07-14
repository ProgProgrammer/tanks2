#pragma once
#include "config.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class IDrawable
{
  public:
    virtual void calculate(sf::Event& event) = 0;
    virtual void draw() = 0;
};