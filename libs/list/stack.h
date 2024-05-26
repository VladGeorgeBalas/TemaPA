#ifndef STACK_H
#define STACK_H
#include "list.h"

//Stack(stiva) - LastInFirstOne
//Operatii
//      - Push - Introduce la inceput
//      - Pop - Extrage primul element
typedef struct list_node *stack;

//Push - Introduce la inceput
void psh(struct list_node *stk_hed, struct list_node *to_psh);

//Pop - Extrage primul element
struct list_node *pop(struct list_node *que_hed);

#endif
