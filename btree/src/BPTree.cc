//
// Created by Mohammad Yazdani on 2019-02-18.
//

#include <BPTree.h>

#include "BPTree.h"
BPTree::BPTree(unsigned int order) : order(order) {}

void
BPTree::add(KV kv) {
    data.push_back(kv);
    if (data.size() / 2)
}


