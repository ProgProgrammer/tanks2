#pragma once
#include "utils.h"
#include "level.h"

class LevelGenerator
{
private:
    Levels m_levels;
public:
    Level getLevel(int& num_level) const;
    void readLevelsFromFile(const std::string& filename, int& num_level);
};