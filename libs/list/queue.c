#include "queue.h"
#include "stdlib.h"

void en_que(queue que_hed, struct list_node *to_que) {
    //gaseste finalul
    struct list_node *tmp = que_hed;
    while (tmp->next) tmp = tmp->next;

    //adauga la final
    tmp->next = to_que;
    to_que->next = NULL;
}

//vezi comentarii pop() din stack.c
struct list_node *de_que(struct list_node *que_hed) {
    if (!que_hed->next)
        return NULL;

    struct list_node *result = que_hed->next;
    que_hed->next = result->next;
    result->next = NULL;

    return result;
}