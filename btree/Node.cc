//
// Created by Mohammad Yazdani on 2019-02-10.
//
#include <iostream>

#include "Node.h"
Node::Node(unsigned long child_cap, NVal value, void *data) : child_cap(child_cap), value(value), data(data) {}

void
Node::push(Node *child)
{

    for (auto i = 0; i < children.size(); i++)
    {
        if (children[i]->value >= child->value)
        {
            if (children.size() < (child_cap / 2)) children.insert(children.begin() + i, child);
            else return children[i]->push(child);
        }
    }
    if (children.empty()) children.push_back(child);
    else if (children.size() < (child_cap / 2)) children.insert(children.end(), child);
    else children[children.size() - 1]->push(child);
}
void *
Node::getData() const
{
    return data;
}
const std::vector<Node *> &
Node::getChildren() const
{
    return children;
}
NVal
Node::getValue() const
{
    return value;
}
void
Node::print(std::string offset)
{
    for (auto child : children)
    {
        std::cout << offset << child->getValue() << " " << *((std::string *) child->getData()) << std::endl;
        child->print(offset + offset[0]);
    }
}
