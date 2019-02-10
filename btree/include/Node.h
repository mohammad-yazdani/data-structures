//
// Created by Mohammad Yazdani on 2019-02-10.
//

#ifndef BTREE_NODE_H
#define BTREE_NODE_H

#include <vector>
#include <string>
#include <unistd.h>
#include "LList.h"

typedef uint64_t NID;
typedef long long int NVal;

class Node : public LList
{
private:
    static NID id_bag;
    NVal value;
    Node *lo_left;
    Node *lo_right;
    unsigned int order;
    bool vertex;
    NID id;

    Node *
    getPrev();

    Node *
    getNext();

    Node *
    push_down(Node *node);

    void
    putBehind(Node *node);

    void
    putForward(Node *node);
public:
    Node(unsigned int order, NVal value);

    NVal
    getValue() const;

    NID
    push(Node *node);

    Node *
    pop(NVal val);

    NID
    getId() const;

    // TODO : For test
    void
    print(std::string offset);
};

#endif //BTREE_NODE_H
