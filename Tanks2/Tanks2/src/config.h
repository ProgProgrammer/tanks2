#pragma once

class Config
{
public:
    int m_dx;
    int m_dy;
    int m_speed_tank;
    float m_width_window;
    float m_height_window;
    float m_tank_width;
    float m_tank_height;
    sf::RenderWindow* m_window;
    Config(const int& x, const int& y, const int& width_win, const int& height_win, const int& t_width, const int& t_height, const int& sp_tank, sf::RenderWindow* window)
        : m_dx(x), m_dy(y), m_width_window(width_win), m_height_window(height_win), m_tank_width(t_width), m_tank_height(t_height), m_speed_tank(sp_tank), m_window(window) {}
};