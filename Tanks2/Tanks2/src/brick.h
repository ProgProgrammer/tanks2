#pragma once
#include "iDrawable.h"
#include "levelgenerator.h"

class Brick : public IDrawable
{
  private:
    const int m_dx;
    const int m_dy;
    const char m_cube;
    const Config* m_config;
    sf::Color m_emptyPlace = sf::Color(0, 0, 0);
    std::vector<sf::Color> m_colors = {sf::Color(192, 192, 192), sf::Color(128, 0, 0),    sf::Color(165, 42, 42),
                                       sf::Color(160, 82, 45),   sf::Color(139, 69, 19),  sf::Color(210, 105, 30),
                                       sf::Color(205, 133, 63),  sf::Color(184, 134, 11), sf::Color(218, 165, 32),
                                       sf::Color(244, 164, 96)};

  public:
    Brick(const int& x, const int& y, const char& ch, const Config* conf);
    void calculate(sf::Event& event) override;
    void draw() override;
};