#pragma once
#include "iDrawable.h"

class Brick : public IDrawable
{
public:
    virtual void calculate() override;
    virtual void draw() override;
};