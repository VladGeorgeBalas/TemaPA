#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/data/data.h"
#include "../../libs/list/list.h"
#include "../../libs/list/utils.h"

float tem_pts(struct team* _tem){
    float result = 0;
    for(unsigned int i = 0; i < _tem->number; i++) {
        result += (_tem->members + i)->points;
    }

    return result;
}

int max_pow_two(int upp_lim){
    int result = 1;

    while(upp_lim!=1)
        upp_lim/=2, result*=2;

    return result;
}

extern void task2(struct list_node* _hed_lst){
    //aflare numar de echipe
    struct list_node* tmp = _hed_lst->next;
    unsigned int num_tem = 0;

    while(tmp) num_tem++, tmp = tmp->next;

    fprintf(stderr, "numarul de echipe : %d\n", num_tem);

    //gasirea numarului maxim de echipe
    unsigned int max_num_tem = max_pow_two(num_tem);
    fprintf(stderr, "maximul de echipe ramase : %d\n\n", max_num_tem);

    //parcurgerea listei plus eliminare
    while(num_tem > max_num_tem)
    {
        #define del_val ((struct team*)(del->value))
        #define tmp_val ((struct team*)(tmp->value))
        struct list_node* del = _hed_lst->next;
        tmp = _hed_lst->next;

        fprintf(stderr, "   to delete --> %s : %f \n", del_val->name, tem_pts(del_val));

        while(tmp->next){
            fprintf(stderr, "%s : %f \n", tmp_val->name, tem_pts(tmp_val));
            if(tem_pts(tmp_val) < tem_pts(del_val))
            {
                del = tmp;
                fprintf(stderr, "   to delete --> %s : %f \n", del_val->name, tem_pts(del_val));
            }
            tmp = tmp->next;
        }
        fprintf(stderr, "\n");

        //eliminarea nodului
        del = extractNode(del, _hed_lst);
        if(del){

            for(int i = 0; i < del_val->number; i++)
            {
                free(del_val->members[i].last_name);
                free(del_val->members[i].first_name);
            }

            free(del_val->members);
            free(del_val->name);

            free(del_val);
        }

        num_tem--;
    }
}