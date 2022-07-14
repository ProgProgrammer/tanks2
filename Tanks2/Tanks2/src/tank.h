#pragma once
#include "i_drawable.h"
#include <chrono>

class Tank : public IDrawable
{
  private:
    float m_speed_tank_px_per_ms;
    float m_tank_width;
    float m_tank_height;
    float m_x_position;
    float m_y_position;
    Config* m_config;
    sf::Texture m_image;
    sf::Sprite m_sprite;
    sf::RenderWindow* m_window;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_last_update_time;

  public:
    Tank(Config* config, sf::RenderWindow* window);
    void calculate(sf::Event& event) override;
    void draw() override;
};