#include <chrono>
#include <thread>
#include "world.h"

World::World() {}

World::~World()
{
    for (int i = 0; i < objects.size(); i++)
    {
        delete objects[i];
    }
}

void World::calculate(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        for (auto objectPtr : objects)
        {
            objectPtr->calculate(event);
        }
    }
}

void World::rendering()
{
    for (int i = 0; i < objects.size(); i++)
    {
        objects[i]->draw();
    }
}

void World::startLoop()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "TestProgram");
    sf::Clock clock;

    Text* text = new Text;
    Tank* tank = new Tank;
    Bullet* bullet = new Bullet;
    Brick* brick = new Brick;

    objects.push_back(text);
    objects.push_back(tank);
    objects.push_back(bullet);
    objects.push_back(brick);

    while (window.isOpen())
    {
        clock.restart();

        sf::Event event;
        window.pollEvent(event);

        calculate(event);
        rendering();

        sf::Time t = clock.getElapsedTime();

        sf::Time pause = sf::milliseconds(40);
        pause = pause - t;

        int num = 1000 / pause.asMilliseconds();

        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1000ms / num);

        if (event.type == sf::Event::Closed)
            window.close();
    }
}