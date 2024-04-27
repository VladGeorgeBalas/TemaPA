#ifndef LIST_H
#define LIST_H

struct list_node{
    void* value;
    struct list_node* next;
};

struct list_node list_node(void* _value);

struct list_node* newList_node(void* _value);

struct list_node freeList_node(struct list_node* _list_node);

struct list_node list();

struct list_node* newList();

struct list_node freeList(struct list_node* _list);

#endif //LIST_H
