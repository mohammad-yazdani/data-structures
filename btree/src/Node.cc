//
// Created by Mohammad Yazdani on 2019-02-10.
//
#include <iostream>
#include <Node.h>

Node::Node(void *data, NVal value, unsigned int order)
    : LList(data), value(value), order(order), vertex(false), lo_left(nullptr), lo_right(nullptr) {}

NVal
Node::getValue() const
{
    return value;
}

void
Node::print(std::string offset)
{
    std::cout << offset << value << std::endl;
    if (next)
        ((Node *) next)->print(offset);
}
Node *
Node::push(Node *node)
{
    // TODO : If vertex push down
    // TODO : else If order just add to list
    // TODO : Else Break the list
    return nullptr;
}
