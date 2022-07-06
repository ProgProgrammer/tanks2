#include <fstream>
#include <string>
#include "levelgenerator.h"

LevelGenerator::LevelGenerator(Levels& levl) : levels(levl) {}

Level LevelGenerator::getRandomLevel() const
{
    const int select_level = getRandomInt(0, number_levels);

    return levels[select_level];
}

Level LevelGenerator::getLevel(int& num_level) const
{
    if (num_level >= 0 && num_level <= number_levels)
        return levels[num_level];
    else
        throw std::runtime_error("There is no such element on the level.");
}

void LevelGenerator::readLevelsFromFile(const std::string& filename, int& num_level)
{
    std::string input_file = filename;
    std::ifstream inFile;
    inFile.open(input_file);
    std::string str_level = "";
    int counter_level = 0;
    levels.resize(1);

    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            std::getline(inFile, str_level);

            if (str_level != "")
                levels[counter_level].push_back(str_level);
            else
            {
                levels.resize(2);
                counter_level++;
            }
        }
    }

    inFile.close();

    number_levels = counter_level;
}