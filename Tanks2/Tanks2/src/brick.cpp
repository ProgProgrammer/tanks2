#include "brick.h"

Brick::Brick(const int& x, const int& y, const char& ch, const Config* conf) : m_dx(x), m_dy(y), m_cube(ch), m_config(conf)
{}

void Brick::calculate(sf::Event& event)
{
    
}

void Brick::draw()
{
    sf::Color color;

    if (m_cube == '.')
    {
        color = m_emptyPlace;
    }
    else
    {
        int elem = castToInt(m_cube);
        color = m_colors[elem];
    }

    sf::RectangleShape rec_shape = sf::RectangleShape(sf::Vector2f(m_config->m_dx, m_config->m_dy));
    rec_shape.setFillColor(color);
    rec_shape.setPosition(m_dx, m_dy);
    rec_shape.setOrigin(rec_shape.getSize().x, rec_shape.getSize().y);

    m_config->m_window->draw(rec_shape);
}