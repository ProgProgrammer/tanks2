#include "brick.h"

Brick::Brick(int& x, int& y, char& ch, Config& conf) : dx(x), dy(y), cell_num(ch), config(conf)
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
        color = colors[(int)cell_num];

    sf::RectangleShape rec_shape = sf::RectangleShape(sf::Vector2f(config.dx, config.dy));
    rec_shape.setFillColor(color);
    rec_shape.setPosition(dx, dy);
    rec_shape.setOrigin(rec_shape.getSize().x / 2, rec_shape.getSize().y / 2);

    window.draw(rec_shape);
}