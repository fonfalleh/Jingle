#include "scene.h"

typedef std::list<GameObject*>::iterator GOsIT;


Scene::Scene(int width, int height, DrawHandler* dhandler, sf::RenderWindow* win):
framecounter(0)
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
    
}

void Scene::update(const sf::Time & currentTime)
{
    //Testing
    /*for(GOsIT it = objs.begin(); it != objs.end(); ++it) //TODO Iterate instead of increment?
    { // Oh god why, this is terrible
        (*it)->update(this);
    }*/
    for(auto o : objs)
    {
        o->update(*this);
    }
    drawer->doStuff(window);

    for(GOsIT it = objs.begin(); it != objs.end(); ++it)
    {
        for(GOsIT innit = objs.begin(); innit != objs.end(); ++innit)
        {
            if(*it != *innit && Utils::CollideChk(**it, **innit))
                    std::cout<<"Hello"<<std::endl; //TODO Collisions are checked here.b
        }
    }
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
