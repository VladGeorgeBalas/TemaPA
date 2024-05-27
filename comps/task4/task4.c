#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/data/data.h"
#include "../../libs/list/list.h"
#include "../../libs/tree/tree.h"
#include "../../libs/list/queue.h"

extern float tem_pts(struct team *_tem);

void del_emp_lst(struct list_node *lst) {
    if (lst) del_emp_lst(lst->next);
    free(lst);
}

struct bee_tre_nod *createNode(void *nod) {
    struct bee_tre_nod *res = malloc(sizeof(struct bee_tre_nod));
    res->val = nod;
    res->rht = NULL;
    res->lft = NULL;
};

void addBeeNod(struct bee_tre_nod *tre, struct team *nod) {
    if (tem_pts(tre->val) == tem_pts(nod)) {
        if (strcmp(((struct team *) tre->val)->name, nod->name) > 0) {
            if (!tre->rht) {
                tre->rht = malloc(sizeof(struct bee_tre_nod));
                tre->rht = createNode(nod);
            } else addBeeNod(tre->rht, nod);
        } else {
            if (!tre->lft) {
                tre->lft = malloc(sizeof(struct bee_tre_nod));
                tre->lft = createNode(nod);
            } else addBeeNod(tre->lft, nod);
        }
    } else {
        if (tem_pts(tre->val) > tem_pts(nod)) {
            if (!tre->rht) {
                tre->rht = malloc(sizeof(struct bee_tre_nod));
                tre->rht = createNode(nod);
            } else addBeeNod(tre->rht, nod);
        } else {
            if (!tre->lft) {
                tre->lft = malloc(sizeof(struct bee_tre_nod));
                tre->lft = createNode(nod);
            } else addBeeNod(tre->lft, nod);
        }
    }
}

void printBeeTre(struct bee_tre_nod *tre_hed, FILE *out, struct list_node *out_put) {
    if (tre_hed->lft)
        printBeeTre(tre_hed->lft, out, out_put);

    if (tre_hed->val) {
        struct team *tem = tre_hed->val;
        unsigned int bff = 34 - strlen(tem->name);

        fprintf(out, "%s", tem->name);
        for (int i = 1; i <= bff; i++)
            fprintf(out, " ");

        fprintf(out, "-  %.2f\n", tem_pts(tre_hed->val));

        en_que(out_put, newList_node(tem));
    }

    if (tre_hed->rht)
        printBeeTre(tre_hed->rht, out, out_put);
}

extern struct list_node *task4(struct list_node *lst_8, FILE *out) {
    struct bee_tre_nod *tre_hed = createNode(lst_8->next->value);

    for (struct list_node *i = lst_8->next->next; i; i = i->next) {
        fprintf(stderr, "    %s --> %f\n", ((struct team *) i->value)->name, tem_pts(i->value));
        addBeeNod(tre_hed, i->value);

        i->value = NULL;
    }

    fprintf(out, "\nTOP 8 TEAMS:\n");
    struct list_node *out_put = malloc(sizeof(struct list_node));
    out_put->next = NULL;
    printBeeTre(tre_hed, out, out_put);

    del_emp_lst(lst_8);

    return out_put;
}
