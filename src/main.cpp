#include "drawhandler.h"
#include "utils.h"
#include "scene.h"

int main()
{
    // Init
    constexpr int height = 315, width = 420;
    const float framerate = 100.0f;
    sf::RenderWindow window{sf::VideoMode(width, height), "JINGLE"};
    window.setFramerateLimit(framerate); //TODO Idunnolols
    
    DrawHandler drawer;
    Scene scene(width, height, &drawer, &window);

    //Timekeeping
    sf::Clock* timer = new sf::Clock();
    sf::Time step = sf::milliseconds(1000) / framerate; //Can't quite go below 60? Is drawing capped by hardware?
    sf::Time elapsed;
    sf::Time nextStep = step;
    while (window.isOpen())
    {   // Loop that ensures updates.
        elapsed += timer->restart();
        if(elapsed < nextStep){
            continue; // Goes back to loop start if it is not time for a new frame yet.
        }
        nextStep += step; // When it is time for a new frame, "reset" the elapsed time.
        
        // Magic stuff. Doesn't work wihout it.
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        scene.update(elapsed);
    }
    return 0;
}
