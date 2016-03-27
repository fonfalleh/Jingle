#include "gameobject.h"
#include "scene.h"

GameObject::GameObject(int x, int y, int r):
    px(x), py(y), radius(r)
{

}

GameObject::GameObject(int x, int y, int vx, int vy, int r):
    px(x), py(y), vx(vx), vy(vy), radius(r)
{
}

GameObject::~GameObject()
{
}

void GameObject::move(int x, int y)
{
     px += x;
     py += y;
}

void GameObject::move()
{
     px += vx;
     py += vy;
}

void GameObject::setPos(int x, int y)
{
    px = x;
    py = y;
}

void GameObject::setVel(int x, int y)
{
    vx = x;
    vy = y;
}


int GameObject::getX()
{
    return px;
}

int GameObject::getY()
{
    return py;
}

int GameObject::getRadius()
{
    return radius;
}
