#include "qTree.h"

qTree::qTree(AABB & border, int limit):
area{border}, center{Point{border.se.x / 2, border.se.y / 2}}, oblimit{limit}
{
}

qTree::~qTree()
{
}

bool AABB::contains(const Point& p)
{
    return (this->se.x - p.x >= this->nw.x && this->se.y - p.y >= this->nw.y);
}

bool AABB::overlaps(AABB & that)
{
    return contains(that.nw) || contains(that.se);
}