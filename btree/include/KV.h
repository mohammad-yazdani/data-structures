//
// Created by Mohammad Yazdani on 2019-02-18.
//

#ifndef BTREE_KV_H
#define BTREE_KV_H

class BPTree;

class KV
{
private:
    unsigned long key;
    void *value;
    BPTree *parent;
public:
    KV(unsigned long key, void *value, BPTree *parent)
        : key(key), value(value), parent(parent) {}
    unsigned long
    getKey() const
    {
        return key;
    }
    void *
    getValue() const
    {
        return value;
    }
    BPTree *
    getParent() const
    {
        return parent;
    }
};

#endif //BTREE_KV_H
