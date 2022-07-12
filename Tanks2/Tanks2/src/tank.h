#pragma once
#include "iDrawable.h"

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Tank : public IDrawable
{
  private:
    int m_speed_tank;
    float m_tank_width;
    float m_tank_height;
    float m_x_position;
    float m_y_position;
    Direction m_direction;
    Config* m_config;
    sf::Texture m_image;
    sf::Sprite m_sprite;

  public:
    Tank(Config* config);
    void calculate(sf::Event& event) override;
    void draw() override;
};