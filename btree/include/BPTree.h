//
// Created by Mohammad Yazdani on 2019-02-11.
//

#ifndef BTREE_BPTREE_H
#define BTREE_BPTREE_H

#include <vector>
#include "Node.h"

class BPTree
{
private:
    unsigned int order;
    bool leaf;
    unsigned long size;
    Node *pivot;
public:
    explicit BPTree(unsigned int order);
    Node *
    add(NVal key, void *value);
};

#endif //BTREE_BPTREE_H
