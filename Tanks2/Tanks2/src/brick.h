#pragma once
#include "iDrawable.h"
#include "levelgenerator.h"
#include "config.h"

class Brick : public IDrawable, public LevelGenerator
{
private:
    Config* config;
public:
    Brick(Config* conf);
    void calculate(sf::Event& event) override;
    void draw() override;
};