//
// Created by Mohammad Yazdani on 2019-02-19.
//

#include "Vertex.h"
Vertex::Vertex(const unsigned long key, const void *value) : KV(key, value) {}

BPTree *
Vertex::getLeft() const
{
    return left;
}

void
Vertex::setLeft(BPTree *left)
{
    Vertex::left = left;
}

BPTree *
Vertex::getRight() const
{
    return right;
}

void
Vertex::setRight(BPTree *right)
{
    Vertex::right = right;
}
