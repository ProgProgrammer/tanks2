#include <chrono>
#include <thread>
#include <string>
#include "world.h"

sf::RenderWindow window(sf::VideoMode(400, 200), "TestProgram");

std::vector<Brick*> createBricks(Config* config, const Level& level)
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
            dx = config->m_dx * (pos_x + 1);
            dy = config->m_dy * (pos_y + 1);
            bricks.push_back(new Brick(dx, dy, cube, window, config));
        }
    }

    return bricks;
}

World::World()
{
    int x = 20;
    int y = 20;
    m_config = new Config(x, y);

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

    m_bricks = createBricks(m_config, level);
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

    delete m_config;
}

void World::calculate(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        sf::Keyboard::W;

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
    for (auto brickPtr : m_bricks)
    {
        brickPtr->draw();
    }

    for (auto objectPtr : m_objects)
    {
        objectPtr->draw();
    }

    window.display();
}

void World::startLoop()
{
    sf::Clock clock;

    Text* text = new Text;

    int tank_width = 30;
    int tank_height = 50;
    int width_window = 400;
    int height_window = 200;

    Tank* tank = new Tank(tank_width, tank_height, window, width_window, height_window);
    Bullet* bullet = new Bullet;

    m_objects.push_back(text);
    m_objects.push_back(tank);
    m_objects.push_back(bullet);

    while (window.isOpen())
    {
        using namespace std::chrono_literals;
        auto start = std::chrono::high_resolution_clock::now();

        sf::Event event;
        window.pollEvent(event);

        calculate(event);
        rendering();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::this_thread::sleep_for(40ms - elapsed);

        if (event.type == sf::Event::Closed)
            window.close();
    }
}