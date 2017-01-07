#include "drawhandler.h"

DrawHandler::DrawHandler(SDL_Window* w)
{
    objects.clear();
    window = w;
    screen = SDL_GetWindowSurface(window);
    scale = 23;
    SDL_Surface * tempSurface = IMG_Load("spritesheet_t.png"); // Loads from compiled directory. Hardcoded :D
    texture = SDL_ConvertSurface( tempSurface, screen->format, 0 );; // Loads from compiled directory.
    SDL_FreeSurface( tempSurface);
}

void DrawHandler::doStuff()
{
    // clears surface (fills surface with black rectangle)
    SDL_FillRect(screen, NULL, 0);
    SDL_Rect * tmp = new SDL_Rect();
    for(auto o : objects){
        tmp->x = o.g->getX();
        tmp->y = o.g->getY();
        tmp->w = DrawHandler::scale;
        tmp->h = DrawHandler::scale;
        SDL_BlitSurface(
            texture, //src
            o.rect, //srcrect
            screen, // dst
            tmp); //dstrect - coords of object drawn
    }
    delete tmp; // Frees the temporary rectangle. Perhaps just make a static instead?
    
    /*
    w->clear();
    for(std::list<GOS>::iterator it = objects.begin();it != objects.end();it++)
    { // Oh god why, this is terrible //More was than is, but still.
        //GOS* tGos = &(*it); //HAVE A LOOK AT THIS GUY, HE'S A "PROGRAMMER" /;_;
        (*it).s->setPosition((*it).g->getX(), (*it).g->getY()); //TODO Tidy
        w->draw(*((*it).s));
    }
    //TODO Draw all the things in different layers/lists.
    w->display();
     */
}

void DrawHandler::addGO(GameObject* go, int x, int y)
{
    GOS gos;

    SDL_Rect* tmp = new SDL_Rect();
    int xs = x*DrawHandler::scale+1; // 1 pixel offset "frame" in this spritesheet (Terrible practice, but oh well. Live and learn.)
    int ys = y*DrawHandler::scale+1;
    tmp->x = xs;
    tmp->y = ys;
    tmp->w = DrawHandler::scale;
    tmp->h = DrawHandler::scale;
    
    
    //s->setTextureRect(sf::IntRect(xs, ys, 21, 21));
    //s->setOrigin(10,10);
    //s->setPosition(go->getX(), go->getY());

    gos.g = go;
    gos.rect = tmp;

    objects.push_back(gos);
    
}
