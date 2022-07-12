#include "world.h"
#include <chrono>
#include <string>
#include <thread>

std::vector<Brick*> createBricks(Config* m_config, const Level& level, sf::RenderWindow* window)
{
    std::vector<Brick*> bricks;
    int dx;
    int dy;

    for (int pos_y = 0; pos_y < level.size(); pos_y++)
    {
        const auto& line = level[pos_y];

        for (int pos_x = 0; pos_x < line.size(); pos_x++)
        {
            const auto& cube = line[pos_x];
            dx = m_config->m_dx * (pos_x + 1);
            dy = m_config->m_dy * (pos_y + 1);
            bricks.push_back(new Brick(dx, dy, cube, m_config, window));
        }
    }

    return bricks;
}

World::World()
{
    int x = 60;
    int y = 60;
    int width_window = 1200;
    int height_window = 600;
    m_window = new sf::RenderWindow(sf::VideoMode(width_window, height_window), "TestProgram");
    m_config = new Config(x, y, width_window, height_window);

    LevelGenerator levelgenerator;
    levelgenerator.readLevelsFromFile("levels.txt");
    Level level;

    try
    {
        int num_level = 1;
        level = levelgenerator.getLevel(num_level);
    }
    catch (std::runtime_error& error)
    {
        std::cout << error.what() << "\n";
    }

    m_bricks = createBricks(m_config, level, m_window);
}

World::~World()
{
    for (auto objectPtr : m_objects)
    {
        delete objectPtr;
    }

    for (auto brickPtr : m_bricks)
    {
        delete brickPtr;
    }

    delete m_window;
    delete m_config;
}

void World::calculate(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        for (auto objectPtr : m_objects)
        {
            objectPtr->calculate(event);
        }

        for (auto brickPtr : m_bricks)
        {
            brickPtr->calculate(event);
        }
    }
}

void World::rendering()
{
    m_window->clear();

    for (auto brickPtr : m_bricks)
    {
        brickPtr->draw();
    }

    for (auto objectPtr : m_objects)
    {
        objectPtr->draw();
    }

    m_window->display();
}

void World::startLoop()
{
    sf::Clock clock;

    Text* text = new Text;
    Tank* tank = new Tank(m_config, m_window);
    Bullet* bullet = new Bullet;

    m_objects.push_back(text);
    m_objects.push_back(tank);
    m_objects.push_back(bullet);

    while (m_window->isOpen())
    {
        using namespace std::chrono_literals;
        auto start = std::chrono::high_resolution_clock::now();

        sf::Event event;
        m_window->pollEvent(event);

        calculate(event);
        rendering();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::this_thread::sleep_for(2ms - elapsed);

        if (event.type == sf::Event::Closed)
            m_window->close();
    }
}