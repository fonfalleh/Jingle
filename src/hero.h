#ifndef HERO_H
#define HERO_H

#include "gameobject.h"
#include <SFML/Window.hpp>
#include "cooldown.h"

class Hero : public GameObject
{
private:
    Cooldown fireCD;
    static const int fireCDFrames = 60;
public:
    Hero(int x, int y);
    void move(int, int);
    void fire(Scene &);
    void readInput(Scene &);
    virtual void update(Scene &);
private:
};

#endif // HERO_H
