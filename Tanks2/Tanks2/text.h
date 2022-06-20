#pragma once
#include "iDrawable.h"

class Text : public IDrawable
{
public:
    virtual void calculate() override;
    virtual void draw() override;
};