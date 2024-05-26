#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/data/data.h"
#include "../../libs/list/list.h"
#include "../../libs/list/utils.h"

struct bee_tre_nod {
    void *val;
    struct bee_tre_nod *lft, *rht;
};

extern float tem_pts(struct team *_tem);

void del_emp_lst(struct list_node *lst) {
    if (lst) del_emp_lst(lst->next);
    free(lst);
}

void addBeeNod(struct bee_tre_nod *tre, struct team *nod) {
    if(tem_pts(tre->val) == tem_pts(nod))
    {
        if(strcmp(((struct team*)tre->val)->name, nod->name) > 0)
        {
            if (!tre->rht) {
                tre->rht = malloc(sizeof(struct bee_tre_nod));
                tre->rht->val = nod;
                tre->rht->rht = NULL;
                tre->rht->lft = NULL;
            } else addBeeNod(tre->rht, nod);
        }
        else
        {
            if (!tre->lft) {
                tre->lft = malloc(sizeof(struct bee_tre_nod));
                tre->lft->val = nod;
                tre->lft->rht = NULL;
                tre->lft->lft = NULL;
            } else addBeeNod(tre->lft, nod);
        }
    }
    else
    {
        if (tem_pts(tre->val) > tem_pts(nod)) {
            if (!tre->rht) {
                tre->rht = malloc(sizeof(struct bee_tre_nod));
                tre->rht->val = nod;
                tre->rht->rht = NULL;
                tre->rht->lft = NULL;
            } else addBeeNod(tre->rht, nod);
        } else {
            if (!tre->lft) {
                tre->lft = malloc(sizeof(struct bee_tre_nod));
                tre->lft->val = nod;
                tre->lft->rht = NULL;
                tre->lft->lft = NULL;
            } else addBeeNod(tre->lft, nod);
        }
    }
}

void printBeeTre(struct bee_tre_nod *tre_hed, FILE* out) {
    if(tre_hed->lft)
        printBeeTre(tre_hed->lft, out);

    if(tre_hed->val) {
        struct team *tem = tre_hed->val;
        unsigned int bff = 34 - strlen(tem->name);

        fprintf(out, "%s", tem->name);
        for (int i = 1; i <= bff; i++)
            fprintf(out, " ");

        fprintf(out, "-  %.2f\n", tem_pts(tre_hed->val));
    }

    if(tre_hed->rht)
        printBeeTre(tre_hed->rht, out);
}

extern void task4(struct list_node *lst_8, FILE* out) {
    struct bee_tre_nod *tre_hed = malloc(sizeof(struct bee_tre_nod));
    tre_hed->val = lst_8->next->value;
    tre_hed->rht = NULL;
    tre_hed->lft = NULL;

    for (struct list_node *i = lst_8->next->next; i; i = i->next) {
        fprintf(stderr, "    %s --> %f\n", ((struct team *) i->value)->name, tem_pts(i->value));
        addBeeNod(tre_hed, i->value);

        i->value = NULL;
    }

    fprintf(out, "\nTOP 8 TEAMS:\n");
    printBeeTre(tre_hed, out);

    del_emp_lst(lst_8);
}
