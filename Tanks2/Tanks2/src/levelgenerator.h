#pragma once
#include "level.h"

class LevelGenerator : virtual public Level
{
private:
    int number_levels = 0;
public:
    std::vector<std::string> getRandomLevel() const;
    void readLevelFromFile(const std::string& filename);
};