#include "qTree.h"

qTree::qTree(AABB & border, int limit, qTree* root):
area{border}, center{Point{border.se.x / 2, border.se.y / 2}}, oblimit{limit},
    nwc{nullptr}, nec{nullptr}, swc{nullptr}, sec{nullptr}, treeroot{this}, isLeaf{true}
{
        //TODO: take some list of objects to create in?
        // OR: don't have insertion as  part of creation, but handled iteratively
}

qTree::~qTree()
{
}
void qTree::subdivide()
{
    //TODO
    isLeaf = false;
    
    //take all objects, split them by region
    //create subtrees, insert objects into new trees
    
}

bool AABB::contains(const Point& p)
{ // Not tested
    return (this->se.x - p.x >= this->nw.x && this->se.y - p.y >= this->nw.y);
}

bool AABB::overlaps(AABB & that)
{ // Not tested
    if((that.nw.x >= nw.x && that.nw.x <= se.x) || (that.se.x <= se.x && that.se.x >= nw.x)){ // horizontal check
        return (that.nw.y >= nw.y && that.nw.y <= nw.y) || (that.se.y <= se.y && that.se.y >= nw.y); //vertical check
    }
    return false;
}
