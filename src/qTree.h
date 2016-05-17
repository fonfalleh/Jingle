#ifndef QTREE_H
#define QTREE_H

#include <vector>
/*
 * TODO:
 * Perhaps static lists of all objects and/or leaf nodes
 * 
 * Manipulation logic and implementation
 *      also decide where to handle, and when to update. Don't rebuild entire tree all the time.
 *      also, multiple trees? Only objects in trees? Only check certain types of objects? Only insert certain types of objects?
 * 
 * Using templates? Or handle game-logic someplace... sync coords etc
 * 
 * Update-functions
 *      update coordinates
 *      move objects between nodes
 * */
struct Point
{
public:
    Point(float sx, float sy):
    x{sx}, y{sy} {}
    float x, y;
};

struct AABB
{
public:
    AABB(Point snw, Point sse):
    nw{snw}, se{sse} {}
    bool contains(const Point &);
    bool overlaps(AABB &);
    const Point nw, se;    
};

class qTree
{
public:
    // Args: AABB area, object limit, and root node
    qTree(AABB &, int, qTree*);
    ~qTree();
    AABB area;
    Point center;
    int oblimit;
    //std::vector<class A> list;
private:
    bool isLeaf;
    void subdivide();
    qTree* nwc, * nec,* swc,* sec;
    qTree* treeroot;
};



#endif // QTREE_H
