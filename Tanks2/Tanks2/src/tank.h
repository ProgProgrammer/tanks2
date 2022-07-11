#pragma once
#include "iDrawable.h"

class Tank : public IDrawable
{
private:
    int m_width_window;
    int m_height_window;
    float m_width;
    float m_height;
    sf::RenderWindow& m_window;
    sf::Texture m_image;
    sf::Sprite m_sprite;

public:
    Tank(int& w, int& h, sf::RenderWindow& window, int& width_window, int& height_window);
    void calculate(sf::Event& event) override;
    void draw() override;
};