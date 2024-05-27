#ifndef TREE_H
#define TREE_H
#include "../list/list.h"

struct bee_tre_nod {
    void *val;
    struct bee_tre_nod *lft, *rht;
};

#endif
