#pragma once
#include <vector>
#include <sstream>

__declspec(dllexport) int getRandomInt(const int min, const int& max);
int castToInt(const char& ch);

using Level = std::vector<std::string>;
using Levels = std::vector<Level>;
Levels levels;