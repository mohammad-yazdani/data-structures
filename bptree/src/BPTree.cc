//
// Created by Mohammad Yazdani on 2019-02-18.
//

#include <BPTree.h>
#include <cstdlib>
#include <algorithm>

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
    auto i = sorted_insert(vertex);
    link(i);

    if (data.size() >= order)
    {
        auto median = data.size()/2;
        auto mid = data.at(median);
        std::vector<Vertex *> left(data.begin(), data.begin() + median);
        std::vector<Vertex *> right(data.begin() + median, data.end());

        auto left_tree = new BPTree(order, left);
        auto right_tree = new BPTree(order, right);
        mid->setLeft(left_tree);
        mid->setRight(right_tree);

        dnode = true;

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

/*
 * TODO : Possibly inefficient
 * */
unsigned long
BPTree::sorted_insert(Vertex *vertex)
{
    for (unsigned long i = 0; i < data.size(); i++)
    {
        if (data.at(i)->getKey() > vertex->getKey())
        {
            data.insert(data.begin() + i, vertex);
            return i;
        }
    }
    data.insert(data.end(), vertex);
    return (data.size() - 1);
}

void
BPTree::link(unsigned long index)
{
    auto mid = data.at(index);
    if (index > 0)
    {
        auto left = data.at(index - 1);
        left->setRight(mid->getLeft());
    }
    if (index < (data.size() - 1))
    {
        auto right = data.at(index + 1);
        right->setLeft(mid->getRight());
    }
}

Vertex *
BPTree::find(unsigned long key)
{
    if (dnode)
    {
        auto next = find_closest(key);
        return next->find(key);
    }

    for (auto v : data)
    {
        if (v->getKey()==key)
            return v;
    }
    return nullptr;
}

void
BPTree::remove(Vertex *vertex)
{
    auto position = std::find(data.begin(), data.end(), vertex);
    if (position!=data.end())
    {
        if (data.size() < (order/2))
        {

        }

        data.erase(position);
    }
}


