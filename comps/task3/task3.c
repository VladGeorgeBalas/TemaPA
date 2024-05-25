#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/data/data.h"
#include "../../libs/list/list.h"
#include "../../libs/list/utils.h"

//Queue - FiFo
typedef struct list_node *queue;

void en_que(queue que_hed, struct list_node *to_que) {
    //gaseste finalul
    struct list_node *tmp = que_hed;
    while (tmp->next) tmp = tmp->next;

    //adauga la final
    tmp->next = to_que;
    to_que->next = NULL;
}

struct list_node *de_que(struct list_node *que_hed) {
    if (!que_hed->next)
        return NULL;

    struct list_node *result = que_hed->next;
    que_hed->next = result->next;
    result->next = NULL;

    return result;
}

//Stack - LiFo
typedef struct list_node *stack;

void psh(struct list_node *stk_hed, struct list_node *to_psh) {
    to_psh->next = stk_hed->next;
    stk_hed->next = to_psh;
}

struct list_node *pop(struct list_node *que_hed) {
    if (!que_hed->next)
        return NULL;

    struct list_node *result = que_hed->next;
    que_hed->next = result->next;
    result->next = NULL;

    return result;
}

int emp(struct list_node *lst_hed) {
    return !!(lst_hed->next);
}

int numElem(struct list_node *hed) {
    struct list_node *tmp = hed->next;
    int result = 0;

    while (tmp) result++, tmp = tmp->next;

    return result;
}

float tem_pts(struct team *_tem);

struct list_node *hep_crt(struct list_node *tem_lst) {
    //initializare heap
    struct list_node *que_hed = (struct list_node *) malloc(sizeof(struct list_node));
    //initializare valori heap head
    que_hed->next = NULL;
    que_hed->value = NULL;

    //pentru fiecare 2 echipe
    for (struct list_node *i = tem_lst->next; i; i = i->next) {
        //initializare nod
        struct list_node *tmp = (struct list_node *) malloc(sizeof(struct list_node));
        tmp->next = NULL;
        tmp->value = (struct list_node **) malloc(2 * sizeof(struct list_node *));

        //adaugare echipe la meci
        ((struct list_node **) tmp->value)[0] = i;
        i = i->next;
        ((struct list_node **) tmp->value)[1] = i;

        //adugare nod
        en_que(que_hed, tmp);
    }

    return que_hed;
}

void addPoint(struct list_node *nod) {
    struct team *tem = (struct team *) nod->value;
    float to_add = 1.0;

    for (int i = 0; i < tem->number; i++)
        tem->members[i].points += to_add;
}

struct {
    struct list_node *win, *lose;
} hep_exe(struct list_node *que_hed) {

    struct list_node *stk_los_hed = (struct list_node *) malloc(sizeof(struct list_node));
    stk_los_hed->next = NULL;

    struct list_node *stk_win_hed = (struct list_node *) malloc(sizeof(struct list_node));
    stk_win_hed->next = NULL;

    while (emp(que_hed)) {
        struct list_node *tmp = de_que(que_hed);
        if (!tmp) fprintf(stderr, "nod gol\n");
#define tmp_tem(num) ((struct team*)(((struct list_node**)tmp->value)[num])->value)
        if (tem_pts(tmp_tem(0)) <= tem_pts(tmp_tem(1))) {
            psh(stk_win_hed, ((struct list_node **) tmp->value)[1]);
            psh(stk_los_hed, ((struct list_node **) tmp->value)[0]);
        } else {
            psh(stk_win_hed, ((struct list_node **) tmp->value)[0]);
            psh(stk_los_hed, ((struct list_node **) tmp->value)[1]);
        }

        addPoint(stk_win_hed->next);

#undef tmp_tem
        free(tmp->value);
        free(tmp);
    }

    typeof(hep_exe(NULL)) result;
    result.win = stk_win_hed;
    result.lose = stk_los_hed;

    return result;
}

void deleteList_node(struct list_node *del, struct list_node *lst_hed);

void del_lst(struct list_node *lst_hed) {
    while (emp(lst_hed)) {
        struct list_node *tmp = pop(lst_hed);

        for (struct player *i = ((struct team *) tmp->value)->members;
             i < ((struct team *) tmp->value)->members + ((struct team *) tmp->value)->number; i++) {
            free(i->first_name);
            free(i->last_name);
        }

        free(((struct team *) tmp->value)->members);
        free(((struct team *) tmp->value)->name);

        free(((struct team *) tmp->value));

        free(tmp);
    }
}

void printQue(struct list_node *mtc, FILE *out) {
    for (struct list_node *j = mtc->next; j; j = j->next) {
        struct team *tem_rht = ((struct list_node **) j->value)[0]->value;
        unsigned int bff_rht = 33 - strlen(tem_rht->name);

        struct team *tem_lft = ((struct list_node **) j->value)[1]->value;
        unsigned int bff_lft = 33 - strlen(tem_lft->name);

        fprintf(out, "%s", tem_rht->name);
        for (int i = 1; i <= bff_rht; i++)
            fprintf(out, " ");

        fprintf(out, "-");

        for (int i = 1; i <= bff_lft; i++)
            fprintf(out, " ");
        fprintf(out, "%s\n", tem_lft->name);
    }
}

void printWin(struct list_node *stk, FILE *out) {
    for (struct list_node *i = stk->next; i; i = i->next) {
        struct team *tem = i->value;
        unsigned int bff_tem = 34 - strlen(tem->name);

        fprintf(out, "%s", tem->name);
        for (int j = 1; j <= bff_tem; j++)
            fprintf(out, " ");

        fprintf(out, "-  %.2f\n", tem_pts(tem));
    }
}

extern struct list_node *task3(struct list_node *_hed_lst, FILE *out) {
    int i = 1;
    for (; numElem(_hed_lst) > 8; i++) {
        struct list_node *hep_hed = hep_crt(_hed_lst);
        fprintf(out, "\n--- ROUND NO:%d\n", i);
        printQue(hep_hed, out);

        typeof(hep_exe(NULL)) res = hep_exe(hep_hed);

        struct list_node *stk_win_hed = res.win;
        struct list_node *stk_los_hed = res.lose;
        fprintf(out, "\nWINNERS OF ROUND NO:%d\n", i);
        printWin(stk_win_hed, out);

        free(hep_hed);

        del_lst(stk_los_hed);
        free(stk_los_hed);

        _hed_lst->next = stk_win_hed->next;
        free(stk_win_hed);
    }

    struct list_node *lst_8 = malloc(sizeof(struct list_node));
    lst_8->next = NULL;

    for (; numElem(_hed_lst) > 1; i++) {
        struct list_node *hep_hed = hep_crt(_hed_lst);
        fprintf(out, "\n--- ROUND NO:%d\n", i);
        printQue(hep_hed, out);

        typeof(hep_exe(NULL)) res = hep_exe(hep_hed);

        struct list_node *stk_win_hed = res.win;
        struct list_node *stk_los_hed = res.lose;
        fprintf(out, "\nWINNERS OF ROUND NO:%d\n", i);
        printWin(stk_win_hed, out);


        struct list_node *tmp = stk_los_hed;
        while (tmp->next) tmp = tmp->next;
        tmp->next = lst_8->next;
        lst_8->next = stk_los_hed->next;


        free(hep_hed);
        free(stk_los_hed);

        _hed_lst->next = stk_win_hed->next;
        free(stk_win_hed);
    }

    return lst_8;
}