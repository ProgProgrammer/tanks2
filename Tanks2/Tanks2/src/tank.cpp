#include "tank.h"

constexpr auto steady_min = std::chrono::steady_clock::time_point::min();

Tank::Tank(Config* config, sf::RenderWindow* window) : m_config(config), m_window(window)
{
    if (!m_image.loadFromFile("images/tank.png"))
    {
        std::cout << "File not found." << std::endl;
    }
    else
    {
        sf::Vector2u size = m_image.getSize();
        m_tank_width = 75;
        m_tank_height = 75;
        m_speed_tank_px_per_ms = 0.4;
        float kx = m_tank_width / size.x;
        float ky = m_tank_height / size.y;
        sf::Sprite sprite(m_image);
        sprite.setOrigin(size.x / 2, size.y / 2);
        m_sprite = sprite;
        m_sprite.setScale(kx, ky);
        m_x_position = m_config->m_width_window / 2 - (m_tank_width / 2);
        m_y_position = m_config->m_height_window - m_tank_height;
        m_sprite.setPosition(m_x_position, m_y_position);
        m_last_update_time = steady_min;
    }
}

void Tank::calculate(sf::Event& event)
{
    int distance_px = 0;

    if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down ||
        event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            using namespace std::chrono_literals;
            auto current_time = std::chrono::high_resolution_clock::now();

            if (m_last_update_time == steady_min)
            {
                m_last_update_time = current_time;
            }

            std::chrono::duration<double, std::milli> elapsed = current_time - m_last_update_time;
            distance_px = m_speed_tank_px_per_ms * elapsed.count();
            std::cout << elapsed.count() << std::endl;
            m_last_update_time = current_time;
        }

        if (event.type == sf::Event::KeyReleased)
        {
            m_last_update_time = steady_min;
        }
    }

    if (event.key.code == sf::Keyboard::Up)
    {
        m_sprite.setRotation(0);
        m_y_position -= distance_px;
    }

    if (event.key.code == sf::Keyboard::Down)
    {
        m_sprite.setRotation(-180);
        m_y_position += distance_px;
    }

    if (event.key.code == sf::Keyboard::Left)
    {
        m_sprite.setRotation(-90);
        m_x_position -= distance_px;
    }

    if (event.key.code == sf::Keyboard::Right)
    {
        m_sprite.setRotation(90);
        m_x_position += distance_px;
    }

    m_sprite.setPosition(m_x_position, m_y_position);
}

void Tank::draw()
{
    m_window->draw(m_sprite);

    sf::CircleShape shape(2);
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(m_x_position - 1, m_y_position - 1);
    m_window->draw(shape);

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(m_tank_width, m_tank_height));
    rectangle.setOutlineThickness(5);
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOrigin(m_tank_width / 2, m_tank_height / 2);
    rectangle.setPosition(m_x_position, m_y_position);
    m_window->draw(rectangle);
}