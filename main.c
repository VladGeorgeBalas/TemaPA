#include <stdio.h>
#include <stdlib.h>
#include "./libs/data/data.h"
#include "./libs/list/list.h"
#include "./libs/list/utils.h"

struct list_node* task1(FILE* _fff_dta);
void task2(struct list_node* _hed_lst);
void task3(struct list_node* _hed_lst);

int main(int argc, char *argv[]){
    //desfacere input-uri
    FILE* fff_tsk = fopen(*(argv + 1), "r");
    FILE* fff_dta = fopen(*(argv + 2), "r");
    FILE* fff_out = fopen(*(argv + 3), "w");

    struct list_node* tsk_1_lst = task1(fff_dta);
    /*//testare task1
    {
        struct list_node *tmp = tsk_1_lst->next;
        while (tmp) {
            fprintf(fff_out, "%s\n", ((struct team *) tmp->value)->name);
            tmp = tmp->next;
        }
    }*/

    task2(tsk_1_lst);

    task3(tsk_1_lst);
    //testare task3
    {
        struct list_node *tmp = tsk_1_lst->next;
        while (tmp) {
            fprintf(fff_out, "%s\n", ((struct team *) tmp->value)->name);
            tmp = tmp->next;
        }
    }

    return 0;
}