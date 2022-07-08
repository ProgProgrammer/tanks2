#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class IDrawable
{
public:
    virtual void calculate(sf::Event& event) = 0;
    virtual void draw() = 0;
};