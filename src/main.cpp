#include "drawhandler.h"
#include "utils.h"
#include "scene.h"
#include "inputhandler.h"
#include <stdio.h>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_video.h"
#include "SDL2/SDL_image.h"

//#include "SDL2/SDL_image.h"

int main()
{
    // Init
    constexpr int height = 315, width = 420;
    
    SDL_Window *window = nullptr;
    SDL_Surface* gScreenSurface = nullptr;
    SDL_Renderer* gRenderer = nullptr;
    
    
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return 0;
    }
    std::cout << "Init ok" << std::endl;
    
    window = SDL_CreateWindow(
        "Jingle!",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        width,                               // width, in pixels
        height,                               // height, in pixels
        0
    );
    gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    gScreenSurface = SDL_GetWindowSurface(window);
    IMG_Init(IMG_INIT_PNG);
    
    SDL_Surface* testSurface = IMG_Load("spritesheet.png"); // Loads from compiled directory.
    if(testSurface == nullptr)
        std::cout << "Spritesheet not so ok" << std::endl;
    else
        std::cout << "Spritesheet quite ok" << std::endl;
        
    SDL_BlitSurface( testSurface, NULL, gScreenSurface, NULL ); //Blits our testsurface onto the window surface 
    
    DrawHandler drawer(window);
    Scene scene(width, height, &drawer, window);

    //Timekeeping
    unsigned int step = 16; // 16 ms per tick ~= 62.5 fps
    unsigned int currentTime = 0;
    unsigned int lastTime = 0;
    
    //TODO better initialization timing
    bool quit = false;
    
    InputHandler inputter;

    while (!quit)
    {   // Loop that ensures updates.
        currentTime = SDL_GetTicks();
        if(currentTime < lastTime + step){
            continue; // Goes back to loop start if it is not time for a new frame yet.
        }
        //nextStep += step; // When it is time for a new frame, "reset" the elapsed time.
        
        // Magic stuff. Doesn't work wihout it. //WIP : SDL-ifying
        //Handle events on queue
        quit = inputter.update();
        scene.update(currentTime);
        SDL_UpdateWindowSurface(window);
        lastTime = currentTime;
    }
    return 0;
}