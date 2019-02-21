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

    unsigned long
    sorted_insert(Vertex *vertex);

    void
    link(unsigned long index);

    BPTree *
    find_closest(unsigned long key);
public:
    explicit BPTree(unsigned int order);
    BPTree(unsigned int order, const std::vector<Vertex *> &data);
    Vertex *
    add(Vertex *vertex);
    void
    remove(Vertex *vertex);
    Vertex *
    find(unsigned long key);
};

#endif //BTREE_BPTREE_H
