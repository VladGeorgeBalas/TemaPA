//
// Created by vlad on 4/26/24.
//

#ifndef UTILS_H
#define UTILS_H

#include "list.h"

void addAtBeginning(struct list_node* _list, struct list_node* _list_node);

void* extractNode(struct list_node* _to_extract, struct list_node* _head);

void addAtEnd(struct list_node* _list, struct list_node* _list_node);

void addAtPos(struct list_node* _list, struct list_node* _list_node);

struct list_node* getPos(struct list_node* _list, unsigned int _pos);

struct list_node deleteAtBeginning(struct list_node* _list, struct list_node* _list_node);

struct list_node deleteAtEnd(struct list_node* _list, struct list_node* _list_node);

struct list_node deleteAtPos(struct list_node* _list, struct list_node* _list_node);

#endif //UTILS_H
