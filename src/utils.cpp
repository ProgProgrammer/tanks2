#include "utils.h"
#include <random>

int getRandomInt(const int min, const int& max)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);
    auto random_integer = uni(rng);
    return random_integer;
}

int castToInt(const char& ch)
{
    std::stringstream ss;
    ss << ch;
    int num = std::stoi(ss.str());

    return num;
}