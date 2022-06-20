#include <chrono>
#include <thread>
#include "world.h"

World::World()
{}

void World::calculate(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        for (int i = 0; i < iDrawable.size(); i++)
        {
            if ((event.key.code == sf::Keyboard::W && i == 1) ||
                event.key.code == sf::Keyboard::S ||
                event.key.code == sf::Keyboard::A ||
                event.key.code == sf::Keyboard::D)  // движение танка
                iDrawable[i]->calculate();
            else if (event.key.code == sf::Keyboard::Space && i != 1 && i != 0)  // стрельба из танка
                iDrawable[i]->calculate();
            else if (event.key.code == sf::Keyboard::Escape && i == 0)  // меню
                iDrawable[i]->calculate();
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

    delete text;
    delete tank;
    delete bullet;
    delete brick;
}