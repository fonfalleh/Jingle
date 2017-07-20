#include "inputhandler.h"
#include "SDL2/SDL.h"


InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

bool InputHandler::update()
{
    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                return true;
            }
            const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
            // for each button mapped in
            std::map<int, bool*> inputs;
        }
}