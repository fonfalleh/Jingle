#include "drawhandler.h"
#include "utils.h"
#include "scene.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_video.h"

int main()
{
    // Init
    constexpr int height = 315, width = 420;
    // sf::RenderWindow window{sf::VideoMode(width, height), "JINGLE"};
    // window.setFramerateLimit(framerate); //TODO Idunnolols
    
    SDL_Window *window = nullptr;
    SDL_Surface* gScreenSurface = nullptr;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        width,                               // width, in pixels
        height,                               // height, in pixels
        0
    );
    gScreenSurface = SDL_GetWindowSurface( window);


    
    DrawHandler drawer;
    Scene scene(width, height, &drawer, window);

    //Timekeeping
    unsigned int step = 16; // 16 ms per tick ~= 62.5 fps
    unsigned int currentTime = 0;
    unsigned int lastTime = 0;
    
    //TODO better initialization timing
    bool quit = false;
    SDL_Event e;

    while (!quit)
    {   // Loop that ensures updates.
        currentTime = SDL_GetTicks();
        if(currentTime < lastTime + step){
            continue; // Goes back to loop start if it is not time for a new frame yet.
        }
        //nextStep += step; // When it is time for a new frame, "reset" the elapsed time.
        
        // Magic stuff. Doesn't work wihout it. //WIP : SDL-ifying
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }
        scene.update(currentTime);
        SDL_UpdateWindowSurface(window);

        lastTime = currentTime;
    }
    return 0;
}