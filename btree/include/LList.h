//
// Created by Mohammad Yazdani on 2019-02-10.
//

#ifndef BTREE_LLIST_H
#define BTREE_LLIST_H

class LList
{
protected:
    LList * prev;
    LList * next;
    void * data;
public:
    LList(void *data);
};

#endif //BTREE_LLIST_H
