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
    SDL_Window* window;
    SDL_Surface* screen;
    DrawHandler(SDL_Window *);
    void doStuff();
private:
    // GOSes are used during drawing and contains a gameobject and SDL_Rect that points out the associated sprite coordinates in the spritesheet "texture".
    struct GOS
    {
        GameObject *g;
        SDL_Rect *rect;
    };
    int scale; // Assuming gridlike spritesheet, scale is the height and width of one sprite.
    std::list<GOS> objects;
};

#endif // DRAWHANDLER_H
