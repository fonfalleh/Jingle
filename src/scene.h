#ifndef SCENE_H
#define SCENE_H

#include "gameobject.h"
#include "hero.h"
#include "baddy.h"
#include "bullet.h"
#include "drawhandler.h"
#include "utils.h"
#include "inputhandler.h"
#include <vector>
#include <queue>

#include "SDL2/SDL.h"

class Scene
{
private:
    SDL_Window* window;
    DrawHandler* drawer;
    InputHandler inputter;
    Hero *hero;
    std::vector<GameObject*> objs;
    std::vector<Bullet*> activeBullets;
    std::queue<Bullet*> passiveBullets;
    void addObject(GameObject& o);
    std::vector<int>::iterator currentElem;
public:
    Scene(int, int, DrawHandler*, SDL_Window*);
    void update(const int&, SDL_Event*);
    void fireBullet(int, int, int, int); //TODO lols
};

#endif // SCENE_H
