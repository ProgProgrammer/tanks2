#include <fstream>
#include <string>
#include "levelgenerator.h"
#include "random_mover.h"

std::vector<std::string> LevelGenerator::getRandomLevel() const
{
    const int select_level = getRandomIntDll(0, number_levels);

    return levels[select_level];
}

void LevelGenerator::readLevelFromFile(const std::string& filename)
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
                str_level = "";
                levels.resize(2);
                counter_level++;
            }
        }
    }

    inFile.close();

    number_levels = counter_level;
}