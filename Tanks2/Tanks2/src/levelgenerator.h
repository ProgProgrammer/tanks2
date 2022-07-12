#pragma once
#include "level.h"
#include "utils.h"

class LevelGenerator
{
  private:
    Levels m_levels;

  public:
    Level getLevel(int& num_level) const;
    void readLevelsFromFile(const std::string& filename);
};