#include <chrono>
#include <thread>
#include <string>
#include "world.h"
#include "levelgenerator.h"

std::vector<Brick*> createBricks()
{
    LevelGenerator levelgenerator;
    std::string str = "levels.txt";
    levelgenerator.readLevelFromFile(str);
    std::vector<std::string> str_arr = levelgenerator.getRandomLevel();

    int x = 20;
    int y = 20;
    Config config(x, y);
    std::vector<Brick*> bricks;

    for (int i = 0; i < str_arr.size(); i++)
    {
        for (int a = 0; a < str_arr[i].size(); a++)
        {
            int dx = x * a;
            int dy = y * i;
            bricks.push_back(new Brick(dx, dy, str_arr[i][a], config));
        }
    }

    return bricks;
}

World::World() 
{
    bricks = createBricks();
}

World::~World()
{
    for (auto objectPtr : objects)
    {
        delete objectPtr;
    }

    for (auto brickPtr : bricks)
    {
        delete brickPtr;
    }

    delete config;
}

void World::calculate(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        for (auto objectPtr : objects)
        {
            objectPtr->calculate(event);
        }

        rendering();
    }
}

void World::rendering()
{
    for (auto objectPtr : objects)
    {
        objectPtr->draw();
    }

    for (auto brickPtr : bricks)
    {
        brickPtr->draw();
    }

    window.display();
}

void World::startLoop()
{
    sf::Clock clock;

    Text* text = new Text;
    Tank* tank = new Tank;
    Bullet* bullet = new Bullet;

    objects.push_back(text);
    objects.push_back(tank);
    objects.push_back(bullet);

    while (window.isOpen())
    {
        using namespace std::chrono_literals;
        auto start = std::chrono::high_resolution_clock::now();

        sf::Event event;
        window.pollEvent(event);

        calculate(event);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::this_thread::sleep_for(40ms - elapsed);

        if (event.type == sf::Event::Closed)
            window.close();
    }
}