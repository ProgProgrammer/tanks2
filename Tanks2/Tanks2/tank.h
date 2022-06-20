#pragma once
#include "iDrawable.h"

class Tank : public IDrawable
{
public:
    virtual void calculate() override;
    virtual void draw() override;
};