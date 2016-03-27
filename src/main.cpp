#include "drawhandler.h"
#include "utils.h"
#include "scene.h"

int main()
{
    // Init
    constexpr int height = 315, width = 420;
    sf::RenderWindow window{sf::VideoMode(width, height), "BOOLET"};
    window.setFramerateLimit(200); //TODO Idunnolols
    DrawHandler drawer;
    Scene scene(width, height, &drawer, &window);

    //Timekeeping
    sf::Clock* timer = new sf::Clock();
    sf::Time step = sf::milliseconds(1000) / 60.0f; //60 fps //Can't quite go below 60? Is drawing capped by hardware?
    sf::Time elapsed;
    int fpf = 0;
    while (window.isOpen())
    {
        elapsed += timer->restart();
        if(elapsed < step){
            fpf++;
            continue;
        }
        elapsed -= step;
        // std::cout<<fpf<<std::endl;
        fpf=0;
        // Magic stuff. Doesn't work wihout it.
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        scene.update();
    }
    return 0;
}
