#include "hero.h"
#include "scene.h"
Hero::Hero(int x, int y):
    GameObject(x,y,5), fireCD(fireCDFrames)
{
}
//Hero::~Hero(){0;}


void Hero::readInput(Scene& s)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        GameObject::move(0, -1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        GameObject::move(0, 1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        GameObject::move(-1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        GameObject::move(1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        fire(s);
    //std::cout<<"X: " << getX() << " Y: " << getY() << std::endl;
}

void Hero::update(Scene& s)
{
    fireCD.tick();
    readInput(s);
}

void Hero::fire(Scene& s){
    if(!fireCD.block()){
        s.fireBullet(px, py, 0, -2); //TODO MAGIC
        fireCD.restart();
    }
}
