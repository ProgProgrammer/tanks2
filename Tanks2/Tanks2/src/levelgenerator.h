#pragma once
#include "utils.h"

class LevelGenerator
{
private:
    int number_levels = 0;
    Levels& levels;
public:
    LevelGenerator(Levels& levl);
    Level getRandomLevel() const;
    Level getLevel(int& num_level) const;
    void readLevelsFromFile(const std::string& filename, int& num_level);
};