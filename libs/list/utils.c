#include "utils.h"
#include <stdlib.h>

void addAtBeginning(struct list_node* _list, struct list_node* _list_node){
    _list_node->next = _list->next;
    _list->next = _list_node;
}

void addAtEnd(struct list_node* _list, struct list_node* _list_node){
    struct list_node* tmp = _list;

    while(tmp->next){
        tmp = tmp->next;
    }

    //inutil dar garanteaza ca next este NULL pentru ultimul element
    //in caz ca programatorul este amator si nu se pricepe
    _list_node->next = tmp->next;
    tmp->next = _list_node;
}

void addAtPos(struct list_node* _list, struct list_node* _list_node){
    //de completat, dar cu grija sa dea eroare in caz ca e prea mare coordonata
}

struct list_node* getPos(struct list_node* _list, unsigned int _pos){
    struct list_node* result;

    for(int i = 1; i <= _pos && result; i++)
        result = result->next;

    return result;
}

struct list_node deleteAtBeginning(struct list_node* _list, struct list_node* _list_node){
    if(_list->next)
    {
        struct list_node result = list_node(_list->next->value);
        struct list_node* tmp = _list->next->next;

        free(_list->next);

        _list->next = tmp;

        return result;
    }

    return list_node(NULL);
}

struct list_node deleteAtEnd(struct list_node* _list, struct list_node* _list_node){

}

struct list_node deleteAtPos(struct list_node* _list, struct list_node* _list_node);