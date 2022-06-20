#pragma once
#include "iDrawable.h"

class Bullet : public IDrawable
{
public:
    virtual void calculate() override;
    virtual void draw() override;
};