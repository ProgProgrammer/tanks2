#include "tank.h"

Tank::Tank(int& w, int& h, sf::RenderWindow& window, int& width_window, int& height_window, int& speed_tank) 
    : m_width_tank(w), m_height_tank(h), m_window(window), m_width_window(width_window), m_height_window(height_window), m_speed_tank(speed_tank)
{
    if (!m_image.loadFromFile("images/tank.png"))
    {
        std::cout << "File not found." << std::endl;
    }
    else
    {
        m_half_width_tank = m_width_tank / 2;
        m_half_height_tank = m_height_tank / 2;
        sf::Vector2u size = m_image.getSize();
        float x = m_width_tank / size.x;
        float y = m_height_tank / size.y;
        sf::Sprite sprite(m_image);
        m_sprite = sprite;
        m_sprite.setScale(x, y);
        m_x_position = m_width_window / 2 - (m_width_tank / 2);
        m_y_position = m_height_window - m_height_tank;
        m_sprite.setPosition(m_x_position, m_y_position);
    }    
}


void Tank::calculate(sf::Event& event)
{
    if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
    {
        if (m_top_rotate == false)
        {
            m_sprite.setRotation(0);

            if (m_bottom_rotate == true)
            {
                m_y_position -= m_height_tank;
                m_x_position -= m_width_tank;
            }
            else if (m_right_rotate == true)
            {
                m_x_position -= m_width_tank;
                m_y_position -= (m_height_tank - m_width_tank) / 2;
            }
            else if (m_left_rotate == true)
            {
                m_y_position -= m_height_tank - (m_height_tank - m_width_tank) / 2;
            }

            m_top_rotate = true;
            m_bottom_rotate = false;
            m_left_rotate = false;
            m_right_rotate = false;

            m_sprite.setPosition(m_x_position, m_y_position);
        }
        else if (m_y_position - m_speed_tank >= 0)
        {
            m_y_position -= m_speed_tank;
            m_sprite.setPosition(m_x_position, m_y_position);
        }
    }
    else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
    {
        if (m_bottom_rotate == false)
        {
            m_sprite.setRotation(-(rotate_value * 2));

            if (m_top_rotate == true)
            {
                m_y_position += m_height_tank;
                m_x_position += m_width_tank;
            }
            else if (m_right_rotate == true)
            {
                m_y_position += (m_height_tank + m_width_tank) / 2;
            }
            else if (m_left_rotate == true)
            {
                m_x_position += m_width_tank;
                m_y_position += (m_height_tank - m_width_tank) / 2;
            }

            m_bottom_rotate = true;
            m_top_rotate = false;
            m_left_rotate = false;
            m_right_rotate = false;
            m_sprite.setPosition(m_x_position, m_y_position);
        }
        else if (m_y_position + m_speed_tank <= m_height_window)
        {
            m_y_position += m_speed_tank;
            m_sprite.setPosition(m_x_position, m_y_position);
        }
    }
    else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
    {
        if (m_left_rotate == false)
        {
            m_sprite.setRotation(-rotate_value);

            if (m_bottom_rotate == true)
            {
                m_y_position -= m_height_tank;
                m_x_position -= m_width_tank;
            }
            else if (m_right_rotate == true)
            {
                m_x_position -= m_width_tank;
                m_y_position -= (m_height_tank - m_width_tank) / 2;
            }

            m_top_rotate = false;
            m_bottom_rotate = false;
            m_left_rotate = true;
            m_right_rotate = false;

            m_y_position += (m_height_tank + m_width_tank) / 2;
            m_sprite.setPosition(m_x_position, m_y_position);
        }
        else if (m_x_position - m_speed_tank >= 0)
        {
            m_x_position -= m_speed_tank;
            m_sprite.setPosition(m_x_position, m_y_position);
        }
    }
    else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
    {
        if (m_right_rotate == false)
        {
            m_sprite.setRotation(rotate_value);

            if (m_bottom_rotate == true)
            {
                m_y_position -= m_height_tank;
                m_x_position -= m_width_tank;
            }
            else if (m_left_rotate == true)
            {
                m_y_position -= m_height_tank - (m_height_tank - m_width_tank) / 2;
            }

            m_top_rotate = false;
            m_bottom_rotate = false;
            m_right_rotate = true;
            m_left_rotate = false;

            m_x_position += m_width_tank;
            m_y_position += (m_height_tank - m_width_tank) / 2;
            m_sprite.setPosition(m_x_position, m_y_position);
        }
        else if (m_x_position + m_speed_tank <= m_width_window)
        {
            m_x_position += m_speed_tank;
            m_sprite.setPosition(m_x_position, m_y_position);
        }
    }
}

void Tank::draw()
{
    m_window.draw(m_sprite);
}