//
// Created by Mohammad Yazdani on 2019-02-18.
//

#ifndef BTREE_BPTREE_H
#define BTREE_BPTREE_H

#include <vector>
#include "Vertex.h"

class BPTree
{
private:
    unsigned int order;
    std::vector<Vertex *> data;
    bool root;
    bool dnode;
public:
    explicit BPTree(unsigned int order);
    BPTree(unsigned int order, const std::vector<Vertex *> &data);
    Vertex *
    add(Vertex *vertex);
    BPTree *
    find_closest(unsigned long key);
};

#endif //BTREE_BPTREE_H
