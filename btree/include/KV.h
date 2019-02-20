//
// Created by Mohammad Yazdani on 2019-02-18.
//

#ifndef BTREE_KV_H
#define BTREE_KV_H

class KV
{
private:
    const unsigned long key;
    const void *value;
public:
    KV(const unsigned long key, const void *value) : key(key), value(value) {}

    const unsigned long
    getKey() const
    {
        return key;
    }

    const void *
    getValue() const
    {
        return value;
    }
};

#endif //BTREE_KV_H
