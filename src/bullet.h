#ifndef BULLET_H
#define BULLET_H

#include "gameobject.h"

class Bullet : public GameObject
{
public:
    Bullet(int, int);
    Bullet(int, int, int, int);
    virtual ~Bullet();
    virtual void update(Scene &);
    void deactivate();
    void recycle(int, int, int, int);
private:
    bool active;
};

#endif // BULLET_H
