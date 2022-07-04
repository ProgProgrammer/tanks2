#pragma once

class Config
{
public:
    const int& dx;
    const int& dy;
    Config(const int& x, const int& y) : dx(x), dy(y) {}
};