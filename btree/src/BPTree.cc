//
// Created by Mohammad Yazdani on 2019-02-11.
//

#include <BPTree.h>

#include "BPTree.h"

BPTree::BPTree(unsigned int order) : order(order), leaf(true), size(0), pivot(nullptr) {}

Node *
BPTree::add(NVal key, void *value)
{
    if (!pivot)
        pivot = new Node(key, value);
    else if (leaf)
    {
        if (size < order)
        {
            pivot->push(new Node(key, value));
        }
        else
        {
            // TODO : Split
        }
    }
    else
    {
        auto next = pivot->closest(key);
        Node *cb;
        if (key < next->getValue())
        {
            cb = next->getLo()->add(key, value);
        }
        else
        {
            cb = next->getHi()->add(key, value);
        }
        if (cb)
        {
            if (size < order)
            {
                pivot->push(new Node(key, value));
            }
            else
            {
                // TODO : Split
            }
        }
    }
    return nullptr;
}
