//
// Created by Mohammad Yazdani on 2019-02-10.
//
#include <iostream>
#include <Node.h>

NID Node::id_bag = 0;

Node::Node(unsigned int order, NVal value)
    : order(order), value(value), vertex(false), lo_left(nullptr), lo_right(nullptr)
{
    id = id_bag;
    id_bag += 1;
}

NVal
Node::getValue() const
{
    return value;
}

void
Node::print(std::string offset, bool forward)
{
    std::cout << offset << getValue() << std::endl;
    if (vertex)
    {
        auto padded = offset + offset[0];
        if (lo_left)
        {
            std::cout << padded << "left:" << std::endl;
            lo_left->print(padded, false);
        }
        if (lo_right)
        {
            std::cout << padded << "right:" << std::endl;
            lo_right->print(padded, true);
        }
    }
    if (forward && getNext())
        getNext()->print(offset, forward);
    else if (!forward && getPrev())
        getPrev()->print(offset, forward);
}

NID
Node::push(Node *node)
{
    if (vertex)
    {
        if (push_down(node))
        {
            // TODO : Throw exception
            exit(1234);
        }
    }

    if (node->value > value)
    {
        if (getNext())
        {
            getNext()->push(node);
        }
        else
        {
            putForward(node);
        }
    }
    else
    {
        if (getPrev() && getPrev()->value > node->value)
        {
            getPrev()->push(node);
        }
        else
        {
            putBehind(node);
        }
    }
    return node->getId();
}
Node *
Node::getPrev()
{
    return (Node *) prev;
}
Node *
Node::getNext()
{
    return (Node *) next;
}
Node *
Node::push_down(Node *node)
{
    (void) node;
    // TODO : else If order just add to list
    // TODO : Else Break the list
    return nullptr;
}
void
Node::putBehind(Node *node)
{
    auto org_behind = getPrev();
    if (org_behind)
    {
        org_behind->setNext(node);
        node->setPrev(org_behind);
    }
    setPrev(node);
    node->setNext(this);
}
void
Node::putForward(Node *node)
{
    auto org_forward = getNext();
    if (org_forward)
    {
        org_forward->setPrev(node);
        node->setNext(org_forward);
    }
    setNext(node);
    node->setPrev(this);
}
NID
Node::getId() const
{
    return id;
}
void
Node::pop()
{
    auto left = getPrev();
    auto right = getNext();
    left->setNext(right);
    right->setPrev(left);
}
void
Node::split()
{
    auto left = getPrev();
    auto right = getNext();
    left->setNext(nullptr);
    right->setPrev(nullptr);
    setPrev(nullptr);
    setNext(nullptr);
    lo_left = left;
    lo_right = right;
    vertex = true;
}
