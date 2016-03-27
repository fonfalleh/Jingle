#include "cooldown.h"

Cooldown::Cooldown(int frames):
    frames(frames)
{
    count = 0;
}
void Cooldown::restart()
{
    count = frames;
}

int Cooldown::tick()
{
    if(count > 0)
        --count;
    return count;
}

bool Cooldown::block()
{
    return count > 0;
}
