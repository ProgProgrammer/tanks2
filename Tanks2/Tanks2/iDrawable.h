#pragma once
#include <iostream>

class IDrawable
{
public:
    virtual void calculate() = 0;
    virtual void draw() = 0;
};