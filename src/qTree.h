#ifndef QTREE_H
#define QTREE_H
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
    qTree(AABB &, int);
    ~qTree();
    AABB area;
    Point center;
    int oblimit;
private:
    qTree* nwc, * nec,* swc,* sec;
};



#endif // QTREE_H
