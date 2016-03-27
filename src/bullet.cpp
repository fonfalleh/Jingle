#include "bullet.h"

Bullet::Bullet(int x, int y):
    GameObject(x, y, 5)
{
}

Bullet::Bullet(int x, int y, int vx, int vy):
    GameObject(x, y, vx, vy, 5), active(true)
{
}

Bullet::~Bullet()
{
    0;
}

void Bullet::update(Scene& s)
{
    //TODO something clever.
    if(active)
        move();

}

void Bullet::deactivate()
{
    px = -10;
    py = -10;
    vx = 0;
    vy = 0;
    active = false;
}

void Bullet::recycle(int x, int y, int vx, int vy)
{
    px = x;
    py = y;
    this->vx = vx;
    this->vy = vy;
    active = true;
}
