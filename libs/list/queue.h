#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

//Queue(coade) - FirstInFirstOne
//Operatii
//      - enqueue - Introduce la final
//      - dequeue - Extrage primul element
typedef struct list_node *queue;

//enqueue - Introduce la final
void en_que(queue que_hed, struct list_node *to_que);

//dequeue - Extrage primul element
struct list_node *de_que(struct list_node *que_hed);

#endif //TEMAPA_QUEUE_H
