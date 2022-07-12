#include "tank.h"

Tank::Tank(Config* config) : m_config(config)
{
    if (!m_image.loadFromFile("images/tank.png"))
    {
        std::cout << "File not found." << std::endl;
    }
    else
    {
        m_half_width_tank = m_config->m_tank_width / 2;
        m_half_height_tank = m_config->m_tank_height / 2;
        sf::Vector2u size = m_image.getSize();
        float x = m_config->m_tank_width / size.x;
        float y = m_config->m_tank_height / size.y;
        sf::Sprite sprite(m_image);
        m_sprite = sprite;
        m_sprite.setScale(x, y);
        m_x_position = m_config->m_width_window / 2 - (m_config->m_tank_width / 2);
        m_y_position = m_config->m_height_window - m_config->m_tank_height;
        m_sprite.setPosition(m_x_position, m_y_position);
    }    
}


void Tank::calculate(sf::Event& event)
{
    if (event.key.code == sf::Keyboard::Up)
    {
        if (m_top_rotate == false)
        {
            m_sprite.setRotation(0);

            if (m_bottom_rotate == true)
            {
                m_y_position -= m_config->m_tank_height;
                m_x_position -= m_config->m_tank_width;
            }
            else if (m_right_rotate == true)
            {
                m_x_position -= m_config->m_tank_width;
                m_y_position -= (m_config->m_tank_height - m_config->m_tank_width) / 2;
            }
            else if (m_left_rotate == true)
            {
                m_y_position -= m_config->m_tank_height - (m_config->m_tank_height - m_config->m_tank_width) / 2;
            }

            m_top_rotate = true;
            m_bottom_rotate = false;
            m_left_rotate = false;
            m_right_rotate = false;
        }
        else if (m_y_position - m_config->m_speed_tank >= 0)
        {
            m_y_position -= m_config->m_speed_tank;
        }

        m_sprite.setPosition(m_x_position, m_y_position);
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
        if (m_bottom_rotate == false)
        {
            m_sprite.setRotation(-(rotate_value * 2));

            if (m_top_rotate == true)
            {
                m_y_position += m_config->m_tank_height;
                m_x_position += m_config->m_tank_width;
            }
            else if (m_right_rotate == true)
            {
                m_y_position += (m_config->m_tank_height + m_config->m_tank_width) / 2;
            }
            else if (m_left_rotate == true)
            {
                m_x_position += m_config->m_tank_width;
                m_y_position += (m_config->m_tank_height - m_config->m_tank_width) / 2;
            }

            m_bottom_rotate = true;
            m_top_rotate = false;
            m_left_rotate = false;
            m_right_rotate = false;
        }
        else if (m_y_position + m_config->m_speed_tank <= m_config->m_height_window)
        {
            m_y_position += m_config->m_speed_tank;
        }

        m_sprite.setPosition(m_x_position, m_y_position);
    }
    else if (event.key.code == sf::Keyboard::Left)
    {
        if (m_left_rotate == false)
        {
            m_sprite.setRotation(-rotate_value);

            if (m_bottom_rotate == true)
            {
                m_y_position -= m_config->m_tank_height;
                m_x_position -= m_config->m_tank_width;
            }
            else if (m_right_rotate == true)
            {
                m_x_position -= m_config->m_tank_width;
                m_y_position -= (m_config->m_tank_height - m_config->m_tank_width) / 2;
            }

            m_top_rotate = false;
            m_bottom_rotate = false;
            m_left_rotate = true;
            m_right_rotate = false;

            if (m_x_position + m_config->m_tank_height > m_config->m_width_window)
            {
                m_x_position -= m_config->m_tank_height - m_config->m_tank_width;
            }

            m_y_position += (m_config->m_tank_height + m_config->m_tank_width) / 2;
        }
        else if (m_x_position - m_config->m_speed_tank >= 0)
        {
            m_x_position -= m_config->m_speed_tank;
        }

        m_sprite.setPosition(m_x_position, m_y_position);
    }
    else if (event.key.code == sf::Keyboard::Right)
    {
        if (m_right_rotate == false)
        {
            m_sprite.setRotation(rotate_value);

            if (m_bottom_rotate == true)
            {
                m_y_position -= m_config->m_tank_height;
                m_x_position -= m_config->m_tank_width;
            }
            else if (m_left_rotate == true)
            {
                m_y_position -= m_config->m_tank_height - (m_config->m_tank_height - m_config->m_tank_width) / 2;
            }

            m_top_rotate = false;
            m_bottom_rotate = false;
            m_right_rotate = true;
            m_left_rotate = false;

            m_x_position += m_config->m_tank_width;

            if (m_x_position - m_config->m_tank_height < 0)
            {
                m_x_position += m_config->m_tank_height - m_config->m_tank_width;
            }

            m_y_position += (m_config->m_tank_height - m_config->m_tank_width) / 2;
        }
        else if (m_x_position + m_config->m_speed_tank <= m_config->m_width_window)
        {
            m_x_position += m_config->m_speed_tank;
        }

        m_sprite.setPosition(m_x_position, m_y_position);
    }
}

void Tank::draw()
{
    m_config->m_window->draw(m_sprite);
}