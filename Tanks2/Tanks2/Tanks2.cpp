#include <iostream>
#include "world.h"

int main()
{
    Text* text = new Text;
    Tank* tank = new Tank;
    Bullet* bullet = new Bullet;
    Brick* brick = new Brick;

    std::vector<IDrawable*> iDrawable;

    iDrawable.push_back(text);
    iDrawable.push_back(tank);
    iDrawable.push_back(bullet);
    iDrawable.push_back(brick);

    World world(iDrawable);
    world.startLoop();

    delete text;
    delete tank;
    delete bullet;
    delete brick;
}
