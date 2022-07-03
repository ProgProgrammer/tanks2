#include <chrono>
#include <thread>
#include "world.h"
#include "levelgenerator.h"

World::World() {}

World::~World()
{
    for (auto objectPtr : objects)
    {
        delete objectPtr;
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
}

void World::startLoop()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "TestProgram");
    sf::Clock clock;

    Text* text = new Text;
    Tank* tank = new Tank;
    Bullet* bullet = new Bullet;
    int x = 20;
    int y = 20;
    config = new Config(x, y);
    Brick* brick = new Brick(config);

    objects.push_back(text);
    objects.push_back(tank);
    objects.push_back(bullet);
    objects.push_back(brick);

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