#include "tank.h"

Tank::Tank(int& w, int& h, sf::RenderWindow& window, int& width_window, int& height_window) : m_width(w), m_height(h), m_window(window), m_width_window(width_window), m_height_window(height_window)
{
    if (!m_image.loadFromFile("tank.png"))
    {
        std::cout << "File not found." << std::endl;
    }
    else
    {
        sf::Vector2u size = m_image.getSize();
        float x = m_width / size.x;
        float y = m_height / size.y;
        sf::Sprite sprite(m_image);
        m_sprite = sprite;
        m_sprite.setScale(x, y);
        m_sprite.setPosition(10, 10);
    }    
}


void Tank::calculate(sf::Event& event)
{
    //std::cout << "calculateTank" << std::endl;
}

void Tank::draw()
{
    m_window.draw(m_sprite);
}