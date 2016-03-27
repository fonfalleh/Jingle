#ifndef DRAWHANDLER_H
#define DRAWHANDLER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "gameobject.h"


class DrawHandler
{
public:
    void addGO(GameObject*, int, int);
    sf::Texture texture;
    DrawHandler();
    void doStuff(sf::RenderWindow *);
private:
    struct GOS
    {
        GameObject *g;
        sf::Sprite *s;
    };
    int scale;
    std::list<GOS> objects;
};

#endif // DRAWHANDLER_H
