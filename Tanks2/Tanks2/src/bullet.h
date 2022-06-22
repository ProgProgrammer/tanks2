#pragma once
#include "iDrawable.h"

class Bullet : public IDrawable
{
public:
    void calculate() override;
    void draw() override;
};