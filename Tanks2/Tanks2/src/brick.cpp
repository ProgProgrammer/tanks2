#include "brick.h"

Brick::Brick(Config* conf)
{
    config = conf;
    std::string str = "levels.txt";
    readLevelFromFile(str);
}

void Brick::calculate(sf::Event& event)
{
    
}

void Brick::draw()
{
    std::vector<std::string> str_arr = getRandomLevel();
    
    for (int i = 0; i < str_arr.size(); i++)
    {
        std::cout << str_arr[i] << std::endl;
    }
}