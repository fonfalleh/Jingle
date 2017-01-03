#ifndef DRAWHANDLER_H
#define DRAWHANDLER_H

#include <iostream>
#include <list>
#include "gameobject.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_video.h"


class DrawHandler
{
public:
    void addGO(GameObject*, int, int);
    SDL_Surface* texture;
    DrawHandler();
    void doStuff(SDL_Window *);
private:
    struct GOS
    {
        GameObject *g;
        SDL_Rect *rect;
    };
    int scale;
    std::list<GOS> objects;
};

#endif // DRAWHANDLER_H
