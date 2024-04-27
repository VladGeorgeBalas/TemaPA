#include "list.h"
#include <stdlib.h>

struct list_node list_node(void* _value){
    struct list_node result;

    result.value = _value;
    result.next = NULL;

    return result;
}

struct list_node* newList_node(void* _value){
    struct list_node* result = (struct list_node*)malloc(sizeof(struct list_node));

    if(!result) return NULL;

    result->value = _value;
    result->next = NULL;

    return result;
}

struct list_node freeList_node(struct list_node* _list_node){
    struct list_node result;

    result.value = _list_node->value;
    result.next = _list_node->next;

    free(_list_node);

    return result;
}

struct list_node list(){
    struct list_node result;

    result.value = NULL;
    result.next = NULL;

    return result;
}

struct list_node* newList(){
    struct list_node* result = (struct list_node*)malloc(sizeof(struct list_node));

    if(!result) return NULL;

    result->value = NULL;
    result->next = NULL;

    return result;
}

struct list_node freeList(struct list_node* _list){
    struct list_node result;

    result.value = _list->value;
    result.next = _list->next;

    free(_list);

    return result;
}