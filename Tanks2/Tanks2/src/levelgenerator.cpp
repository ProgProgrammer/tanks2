#include "levelgenerator.h"
#include <fstream>
#include <iostream>
#include <string>

Level LevelGenerator::getLevel(int& num_level) const
{
    if (num_level < m_levels.size())
        return m_levels[num_level];
    else
        throw std::runtime_error("There is no such element on the level.");
}

void LevelGenerator::readLevelsFromFile(const std::string& filename)
{
    std::string input_file = filename;
    std::ifstream inFile;
    inFile.open(input_file);

    if (inFile.is_open())
    {
        Level current_level;

        while (!inFile.eof())
        {
            std::string str_level = "";
            std::getline(inFile, str_level);

            if (str_level != "")
            {
                current_level.push_back(str_level);
            }
            else
            {
                m_levels.push_back(current_level);
                current_level.clear();
            }
        }

        m_levels.push_back(current_level);
    }

    inFile.close();
}