#ifndef COOLDOWN_H
#define COOLDOWN_H

class Cooldown
{
private:
    int frames;
    int count;
public:
    Cooldown(int);
    void restart();
    int tick();
    bool block();
};

#endif // COOLDOWN_H
