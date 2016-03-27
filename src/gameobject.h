#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// #include "scene.h" FORWARD DECLARATIONS OH MY
class Scene;
class GameObject
{
protected:
    int px;
    int py;
    int vx;
    int vy;
    int radius;

public:
    GameObject(int x, int y, int r); //TODO consistent constructors?
    GameObject(int x, int y, int vx, int vy, int r);
    virtual ~GameObject();
    int getX();
    int getY();
    int getXV();
    int getYV();
    int getRadius();
    void setPos(int, int);
    void setVel(int, int);
    void updateVel(int, int);
    void move(int, int);
    void move();
    virtual void update(Scene&) = 0;
};

#endif // GAMEOBJECT_H
