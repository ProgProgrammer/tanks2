#include <chrono>
#include <thread>
#include "world.h"

World::World() {}

World::~World()
{
    for (int i = 0; i < iDrawable.size(); i++)
    {
        delete iDrawable[i];
    }
}

void World::calculate(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        for (auto objectPtr : iDrawable)
        {
            objectPtr->calculate(event);
        }
    }
}

void World::rendering()
{
    for (int i = 0; i < iDrawable.size(); i++)
    {
        iDrawable[i]->draw();
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

    iDrawable.push_back(text);
    iDrawable.push_back(tank);
    iDrawable.push_back(bullet);
    iDrawable.push_back(brick);

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