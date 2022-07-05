#pragma once
#include "utils.h"

class LevelGenerator
{
private:
    int number_levels = 0;
public:
    Level getRandomLevel() const;
    void readLevelFromFile(const std::string& filename);
};