#include "drawhandler.h"

DrawHandler::DrawHandler()
{
    objects.clear();
    scale = 23;
    texture = IMG_Load("spritesheet.png"); // Loads from compiled directory.

    /*
    if (!texture.loadFromFile("spritesheet_t.png"))
        std::cout<<"NO SPRITESHEET!"<<std::endl;
    else
        std::cout<<"SPRITESHEET!"<<std::endl;
    */
}
//SPRITES ARE 21x21 w 1px border. 23x+1, 23y+1 to get sprite. //+2?
void DrawHandler::doStuff(SDL_Window *w)
{
    // Gets the active surface to draw on
    SDL_Surface* screen = SDL_GetWindowSurface(w);
    // clears surface (fills surface with black rectangle)
    //SDL_FillRect(screen, NULL, 0);
    
    for(auto o : objects){
        SDL_Rect * tmp = new SDL_Rect();
        tmp->x = o.g->getX();
        tmp->y = o.g->getY();
        tmp->w = 21; // TODO LOL MAGICS
        tmp->h = 21; // TODO LOL MAGICS
        
        // std::cout << "X: " << tmp->x << std::endl << "Y: " << tmp->y << std::endl << std::endl ;
        
        SDL_BlitSurface( //TODO fix. Black screen as of now.
            texture, //src
            o.rect, //srcrect
            screen, // dst
            tmp); //dstrect - coords of object drawn
    }
    
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
{   // Magic numbers: SpriteScale: 21px, center: (10,10)
    GOS gos;

    SDL_Rect* tmp = new SDL_Rect();
    int xs = x*DrawHandler::scale+2;
    int ys = y*DrawHandler::scale+2;
    tmp->x = xs;
    tmp->y = ys;
    tmp->x = DrawHandler::scale;
    tmp->y = DrawHandler::scale;
    
    
    //s->setTextureRect(sf::IntRect(xs, ys, 21, 21));
    //s->setOrigin(10,10);
    //s->setPosition(go->getX(), go->getY());

    gos.g = go;
    gos.rect = tmp;

    objects.push_back(gos);
    
}
