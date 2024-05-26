#include "stack.h"
#include <stdlib.h>

void psh(struct list_node *stk_hed, struct list_node *to_psh) {
    //elementele listei se adauga la finalul noului element
    to_psh->next = stk_hed->next;
    //elementul nou se adauga la capul listei
    stk_hed->next = to_psh;
}

struct list_node *pop(struct list_node *que_hed) {
    //daca nu avem un element, returnam 0
    if (!que_hed->next)
        return NULL;

    //altfel, rezultatul este primul element
    struct list_node *result = que_hed->next;
    //restul listei este adaugata la capul listei
    que_hed->next = result->next;
    //rezultatul se formateaza frumos
    result->next = NULL;

    return result;
}