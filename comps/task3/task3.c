#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/data/data.h"
#include "../../libs/list/list.h"
#include "../../libs/list/utils.h"

struct list_node *stack();

struct list_node *heap();

int numElem(struct list_node *hed) {
    struct list_node *tmp = hed->next;
    int result = 0;

    while (tmp) result++, tmp = tmp->next;

    return result;
}

float tem_pts(struct team *_tem);

extern void task3(struct list_node *_hed_lst) {
    struct list_node *stk_los_hed = (struct list_node*) malloc(sizeof(struct list_node));
    stk_los_hed->next = NULL;

    while (numElem(_hed_lst) > 8) {
        struct list_node *hep_hed = (struct list_node*) malloc(sizeof(struct list_node));
        hep_hed->next = NULL;
        hep_hed->value = NULL;

        for (struct list_node *i = _hed_lst->next; i; i = i->next) {
            struct list_node* tmp = hep_hed;
            while(tmp->next) tmp = tmp->next;

            tmp->next = (struct list_node*) malloc (sizeof(struct list_node));
            tmp = tmp->next;

            tmp->next=NULL;
            tmp->value = (struct list_node**) malloc(2 * sizeof(struct list_node*));

            ((struct list_node**)tmp->value) [0] = i;
            i = i->next;
            ((struct list_node**)tmp->value) [1] = i;
        }

        struct list_node *stk_win_hed = (struct list_node*) malloc(sizeof(struct list_node));
        stk_win_hed->next = NULL;

        for (struct list_node *i = hep_hed->next; i; i = i->next) {
#define i_tem(num) ((struct team*)((struct list_node**)i->value)[num]->value)
            if(tem_pts(i_tem(0)) < tem_pts(i_tem(1)))
            {
                {
                    struct list_node* tmp = stk_win_hed->next;
                    stk_win_hed->next = ((struct list_node**)i->value)[0];
                    stk_win_hed->next->next = tmp;
                }
                {
                    struct list_node* tmp = stk_los_hed->next;
                    stk_los_hed->next = ((struct list_node**)i->value)[1];
                    stk_los_hed->next->next = tmp;
                }
            }
            else
            {
                {
                    struct list_node* tmp = stk_win_hed->next;
                    stk_win_hed->next = ((struct list_node**)i->value)[1];
                    stk_win_hed->next->next = tmp;
                }
                {
                    struct list_node* tmp = stk_los_hed->next;
                    stk_los_hed->next = ((struct list_node**)i->value)[0];
                    stk_los_hed->next->next = tmp;
                }
            }
#undef i_tem
        }

        {
            struct list_node* tmp = hep_hed;
            struct list_node* tmp_nxt = hep_hed->next;

            while(tmp_nxt){
                free(tmp->value);
                free(tmp);

                tmp = tmp_nxt;
                tmp_nxt = tmp_nxt->next;
            }
        }

        _hed_lst->next = stk_win_hed->next;
    }

    /*
     *
     *
     * VEZI SA FACI CURAT IN STIV DE PIERZATORI !!!!
     *
     *
     */
}















