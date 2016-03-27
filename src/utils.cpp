#include "utils.h"

bool Utils::CollideChk(GameObject& a, GameObject& b)
{
    //All GO's have a hitbox-circle.
    // Have 2 points.
    // Distance == sqrt(dx^2+dy^2)
    // Distance^2 == dx^2 + dy^2
    // Critical distance = r1 + r2

    //if points have a distance less than crit, return true
    int dx2 = (a.getX() - b.getX());
    dx2 *= dx2; //dx^2 //TODO De-uglify?

    int dy2 = (a.getY() - b.getY());
    dy2 *= dy2;

    int cdist = a.getRadius() + b.getRadius();
    cdist *= cdist;
    if(cdist >= dx2 + dy2)
        return true;
    return false;
}
