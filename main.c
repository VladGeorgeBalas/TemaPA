#include <stdio.h>
#include <stdlib.h>
#include "./libs/data/data.h"
#include "./libs/list/list.h"
#include "./libs/list/utils.h"

struct list_node* task1(FILE* _fff_dta);
void task2(struct list_node* _hed_lst);
struct list_node* task3(struct list_node* _hed_lst, FILE* out);

int main(int argc, char *argv[]){
    //desfacere input-uri
    FILE* fff_tsk = fopen(*(argv + 1), "r");
    FILE* fff_dta = fopen(*(argv + 2), "r");
    FILE* fff_out = fopen(*(argv + 3), "w");

    int tsk[5] = {0, 0,0, 0, 0};
    for(int i = 0; i < 5; i++)
        fscanf(fff_tsk, "%d", &tsk[i]);

    struct list_node* tsk_1_lst = NULL;
    if(tsk[0]) tsk_1_lst = task1(fff_dta);

    if(tsk[1]) task2(tsk_1_lst);

    if(tsk[1] + tsk[0]){
        struct list_node *tmp = tsk_1_lst->next;
        while (tmp) {
            fprintf(fff_out, "%s\n", ((struct team *) tmp->value)->name);
            tmp = tmp->next;
        }
    }

    struct list_node* lst_8 = NULL;
    if(tsk[2]) lst_8 = task3(tsk_1_lst, fff_out);
    return 0;
}