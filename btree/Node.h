//
// Created by Mohammad Yazdani on 2019-02-10.
//

#ifndef BTREE_NODE_H
#define BTREE_NODE_H

#include <vector>
#include <string>

typedef long long int NVal;

class Node
{
private:
    unsigned long child_cap;
    std::vector<Node *> children;
    NVal value;
    void *data;
public:
    Node(unsigned long child_cap, NVal value, void *data);

    NVal
    getValue() const;

    void *
    getData() const;

    void
    push(Node *child);

    const std::vector<Node *> &
    getChildren() const;

    // TODO : For test
    void
    print(std::string offset);
};

#endif //BTREE_NODE_H
