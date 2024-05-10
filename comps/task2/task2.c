#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/data/data.h"
#include "../../libs/list/list.h"
#include "../../libs/list/utils.h"

extern void task2(struct list_node* _hed_lst){
    //aflare numar de echipe
    struct list_node* tmp = _hed_lst->next;
    unsigned int num_tem = 0;

    while(tmp)
    {
        num_tem++;
        tmp = tmp->next;
    }

    fprintf(stderr, "numarul de echipe : %d\n", num_tem);

    //gasirea numarului maxim de echipe
    unsigned int max_num_tem = 1;

    while(num_tem!=1)
        num_tem/=2, max_num_tem*=2;

    fprintf(stderr, "maximul de echipe ramase : %d\n", max_num_tem);

    //parcurgerea listei plus eliminare
}