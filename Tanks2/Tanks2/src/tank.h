#pragma once
#include "iDrawable.h"

class Tank : public IDrawable
{
  private:
    int m_speed_tank;
    float m_tank_width;
    float m_tank_height;
    float m_x_position;
    float m_y_position;
    Config* m_config;
    sf::Texture m_image;
    sf::Sprite m_sprite;
    sf::RenderWindow* m_window;

  public:
    Tank(Config* config, sf::RenderWindow* window);
    void calculate(sf::Event& event) override;
    void draw() override;
};