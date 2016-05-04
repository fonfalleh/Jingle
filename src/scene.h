#ifndef SCENE_H
#define SCENE_H

#include "gameobject.h"
#include "hero.h"
#include "baddy.h"
#include "bullet.h"
#include "drawhandler.h"
#include "utils.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <queue>

#include "MidiHandler.h"
#include <midifile/MidiEventList.h>

class Scene
{
private:
    sf::RenderWindow* window;
    DrawHandler* drawer;
    Hero *hero;
    std::list<GameObject*> objs;
    std::list<Bullet*> activeBullets;
    std::queue<Bullet*> passiveBullets;
    void addObject(GameObject& o);
    int framecounter;
    MidiHandler *midihandler;
    std::vector<int> frameList;
    bool playback;
    int offset;
    std::vector<int>::iterator currentElem;
public:
    Scene(int, int, DrawHandler*, sf::RenderWindow*);
    void update(const sf::Time&);
    void fireBullet(int, int, int, int); //TODO lols
    void addFrameToList();
    void startPlayback();
};

#endif // SCENE_H
