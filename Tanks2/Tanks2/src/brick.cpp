#include "brick.h"

Brick::Brick(int& x, int& y, char& ch, sf::RenderWindow& wind, Config* conf) : dx(x), dy(y), cell_num(ch), window(wind), config(conf)
{}

void Brick::calculate(sf::Event& event)
{
    
}

void Brick::draw()
{
    sf::Color color;

    if (cell_num == '.')
        color = emptyPlace;
    else
    {
        int elem = (int)cell_num - 48;
        color = colors[elem];
    }

    sf::RectangleShape rec_shape = sf::RectangleShape(sf::Vector2f(config->dx, config->dy));
    rec_shape.setFillColor(color);
    rec_shape.setPosition(dx, dy);
    rec_shape.setOrigin(rec_shape.getSize().x, rec_shape.getSize().y);

    window.draw(rec_shape);
}