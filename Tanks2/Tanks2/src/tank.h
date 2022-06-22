#pragma once
#include "iDrawable.h"

class Tank : public IDrawable
{
public:
    void calculate() override;
    void draw() override;
};