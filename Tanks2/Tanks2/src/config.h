#pragma once

class Config
{
private:
    const int& dx;
    const int& dy;

public:
    Config(const int& x, const int& y) : dx(x), dy(y) {}
};