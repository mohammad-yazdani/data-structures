//
// Created by Mohammad Yazdani on 2019-02-18.
//

#ifndef BTREE_BPTREE_H
#define BTREE_BPTREE_H

#include <vector>
#include "KV.h"

class BPTree
{
private:
    unsigned int order;
    std::vector<KV> data;
public:
    explicit BPTree(unsigned int order);
    void
    add(KV kv);
};

#endif //BTREE_BPTREE_H
