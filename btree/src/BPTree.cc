//
// Created by Mohammad Yazdani on 2019-02-18.
//

#include <BPTree.h>
#include <cstdlib>

#include "BPTree.h"

BPTree::BPTree(unsigned int order) : order(order), root(true), dnode(false) {}

BPTree::BPTree(unsigned int order, const std::vector<Vertex *> &data)
    : order(order), data(data), root(false), dnode(false) {}

Vertex *
BPTree::add(Vertex *vertex)
{
    if (dnode)
    {
        auto closest = find_closest(vertex->getKey());
        vertex = closest->add(vertex);
        if (vertex==nullptr)
            return nullptr;
    }
    data.push_back(vertex); // TODO : Sort

    if (data.size() >= order)
    {
        auto median = data.size()/2;
        auto mid = data.at(median);
        std::vector<Vertex *> left(data.begin(), data.begin() + median);
        std::vector<Vertex *> right(data.begin() + median + 1, data.end());

        auto left_tree = new BPTree(order, left);
        auto right_tree = new BPTree(order, right);
        mid->setLeft(left_tree);
        mid->setRight(right_tree);

        if (root)
            data = {mid};
        else
            return mid;
    }

    return nullptr;
}

BPTree *
BPTree::find_closest(unsigned long key)
{
    Vertex *vertex = data.at(data.size() - 1);
    for (auto v : data)
    {
        if (v->getKey() > key)
        {
            vertex = v;
            break;
        }
    }
    if (vertex->getKey() <= key)
        return vertex->getRight();
    else
        return vertex->getLeft();
}


