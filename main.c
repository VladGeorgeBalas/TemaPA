#include <stdio.h>
#include <stdlib.h>
#include "./libs/data/data.h"
#include "./libs/list/list.h"
#include "./libs/list/utils.h"

extern struct list_node* task1(FILE* _fff_dta);

int main(int argc, char *argv[]){
    FILE* fff_tsk = fopen(*(argv + 1), "r");
    FILE* fff_dta = fopen(*(argv + 2), "r");
    FILE* fff_out = fopen(*(argv + 3), "w");

    struct list_node* tsk_1_lst = task1(fff_dta);
}