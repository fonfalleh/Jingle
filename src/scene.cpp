#include "scene.h"

typedef std::list<GameObject*>::iterator GOsIT; // this... is awkward

// So yeah, here's a lot of ugly initialization
Scene::Scene(int width, int height, DrawHandler* dhandler, sf::RenderWindow* win):
framecounter(0), frameList(), playback(false)
{
    window = win; // TODO: IS THIS EVEN SANE? // Eh. Probably; are pointers.
    drawer = dhandler;
    hero = new Hero(width/2, height/2);
    drawer->addGO(hero, 19, 5);
    Bullet *bullet = new Bullet(10, 10);
    drawer->addGO(bullet, 12, 17);

    objs.push_back(hero);

    Baddy *baddy = new Baddy(10, 10, 5);
    drawer->addGO(baddy, 22, 5);
    objs.push_back(baddy);

    //Midi testing
    midihandler = new MidiHandler("52_Sangerhilsen.MID");
    frameList.push_back(0);
}

void Scene::update(const sf::Time & currentTime)
{
    //Testing
    /*for(GOsIT it = objs.begin(); it != objs.end(); ++it) //TODO Iterate instead of increment?
    { // Oh god why, this is terrible
        (*it)->update(this);
    }*/
    // Runs the update function for all Game Objects
    for(auto o : objs)
    {
        o->update(*this);
    }
    drawer->doStuff(window);
/**
    for(GOsIT it = objs.begin(); it != objs.end(); ++it) //Really, really terrible collision check
    {
        for(GOsIT innit = objs.begin(); innit != objs.end(); ++innit)
        {
            if(*it != *innit && Utils::CollideChk(**it, **innit))
                    std::cout<<"Hello"<<std::endl; //TODO Collisions are checked here.
        }
    }
     **/
    // Midistuffs TODO WIP
    if(playback && *currentElem+ offset <= framecounter){
        fireBullet(150,200,0,-1);
        if(currentElem  != frameList.end())
            currentElem++;
        if (currentElem == frameList.end())
            playback = false;
    }
    std::cout<<"frame: " << framecounter << '\t' << "last pop: " << frameList.back() << std::endl;
    ++framecounter;
}
void Scene::fireBullet(int x, int y, int vx, int vy)
{
    Bullet *bullet = nullptr;
    if(passiveBullets.empty()){
        bullet = new Bullet(x, y, vx, vy);
        objs.push_back(bullet);
        drawer->addGO(bullet, 12, 17);
    }
    else{
         bullet = passiveBullets.front(); //TODO Stufffffs
         passiveBullets.pop();
    }
}


void Scene::addObject(GameObject& o){
    
}

// Midi-stuffs
void Scene::addFrameToList(){
    frameList.push_back(framecounter);
}
void Scene::startPlayback()
{
    if(!playback){
        playback = true;
        currentElem = frameList.begin();
        offset = framecounter;
    }
}
