#pragma once
#include "iDrawable.h"

class Tank : public IDrawable
{
private:
    float m_half_width_tank;
    float m_half_height_tank;
    float m_x_position;
    float m_y_position;
    int rotate_value = 90;
    bool m_top_rotate = true;
    bool m_bottom_rotate = false;
    bool m_left_rotate = false;
    bool m_right_rotate = false;
    Config* m_config;
    sf::Texture m_image;
    sf::Sprite m_sprite;

public:
    Tank(Config* m_config);
    void calculate(sf::Event& event) override;
    void draw() override;
};