//
// Created by Mohammad Yazdani on 2019-02-10.
//

#ifndef BTREE_NODE_H
#define BTREE_NODE_H

#include <vector>
#include <string>
#include "LList.h"

typedef long long int NVal;

class Node : public LList
{
private:
    NVal value;
    Node *lo_left;
    Node *lo_right;
    unsigned int order;
    bool vertex;
public:
    Node(void *data, NVal value, unsigned int order);

    NVal
    getValue() const;

    Node *
    push(Node *node);

    // TODO : For test
    void
    print(std::string offset);
};

#endif //BTREE_NODE_H
