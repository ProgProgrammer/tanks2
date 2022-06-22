#pragma once
#include "iDrawable.h"

class Text : public IDrawable
{
public:
    void calculate() override;
    void draw() override;
};