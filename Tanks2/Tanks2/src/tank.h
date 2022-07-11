#pragma once
#include "iDrawable.h"

class Tank : public IDrawable
{
private:
    int m_width_window;
    int m_height_window;
    float m_width_tank;
    float m_height_tank;
    float m_half_width_tank;
    float m_half_height_tank;
    float m_x_position;
    float m_y_position;
    int m_speed_tank;
    int rotate_value = 90;
    bool m_top_rotate = true;
    bool m_bottom_rotate = false;
    bool m_left_rotate = false;
    bool m_right_rotate = false;
    sf::RenderWindow& m_window;
    sf::Texture m_image;
    sf::Sprite m_sprite;

public:
    Tank(int& w, int& h, sf::RenderWindow& window, int& width_window, int& height_window, int& speed_tank);
    void calculate(sf::Event& event) override;
    void draw() override;
};