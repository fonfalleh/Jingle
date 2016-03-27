#ifndef BADDY_H
#define BADDY_H
#include "gameobject.h"

class Baddy : public GameObject
{
public:
    Baddy(int, int, int);
    virtual void update(Scene&);
};

#endif // BADDY_H
