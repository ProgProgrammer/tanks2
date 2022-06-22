#pragma once
#include "iDrawable.h"

class Brick : public IDrawable
{
public:
    void calculate() override;
    void draw() override;
};