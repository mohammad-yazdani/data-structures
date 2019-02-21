//
// Created by Mohammad Yazdani on 2019-02-19.
//

#ifndef BTREE_VERTEX_H
#define BTREE_VERTEX_H

#include "KV.h"

class BPTree;

class Vertex : public KV
{
private:
    BPTree *left;
    BPTree *right;
public:
    Vertex(unsigned long key, const void *value);

    BPTree *
    getLeft() const;

    void
    setLeft(BPTree *left);

    BPTree *
    getRight() const;

    void
    setRight(BPTree *right);
};

#endif //BTREE_VERTEX_H
