#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/data/data.h"
#include "../../libs/list/list.h"
#include "../../libs/list/utils.h"

char *read(FILE *_stream, unsigned int _length, const char *terminator) {

    char c = getc(_stream);

    if (strchr(terminator, c)) {
        char *result = (char *) malloc(sizeof(char) * (_length + 1));
        if (!result) return NULL;

        *(result + _length) = '\0';
        return result;
    } else {
        char *result = read(_stream, _length + 1, terminator);
        if (!result) return NULL;

        *(result + _length) = c;
        return result;
    }
}

extern struct list_node *task1(FILE *_fff_dta) {
    //numarul de echipe
    unsigned int num_tem;
    //citire numar de echipe
    fscanf(_fff_dta, "%d", &num_tem);
    //initializare lista
    struct list_node *hed_lst = newList();
    //pentru fiecare dintre echipe
    for (unsigned int i = 1; i <= num_tem; i++) {
        struct team *tem = (struct team *) malloc(sizeof(struct team));
        if (!tem) fprintf(stderr, "Esec alocare memorie pt echipa nr %d\n", i);
        //citim numarul de membri
        //fscanf(_fff_dta, "%d", &num_mem);
        char *_num_mem = read(_fff_dta, 0, " ");
        if (!num_tem) fprintf(stderr, "Nu s-a putut citi numarul de membrii ai echipei\n");
        else {
            sscanf(_num_mem, "%d", &tem->number);
            free(_num_mem);
        }
        //initializam vectorul de coechipieri
        tem->members = (struct player *) malloc(sizeof(struct player) * tem->number);
        if (!tem->members) fprintf(stderr, "mem err membri echipa nr %d\n", i);
        //citire si alocare nume echipa
        tem->name = read(_fff_dta, 0, "\n");
        if (!tem->name) fprintf(stderr, "mem err nume echipa nr %d\n", i);
        //pentru fiecare membru al echipei
        for (int j = 0; j < tem->number; j = j + 1) {
            //selectam membrul echipei
            struct player *mem = tem->members + j;
            mem->last_name = read(_fff_dta, 0, " \n");
            if (!mem->last_name) fprintf(stderr, "   Nu s-a putut aloca mem pt LN al membrului %d\n", j);
            mem->first_name = read(_fff_dta, 0, " \n");
            if (!mem->last_name) fprintf(stderr, "   Nu s-a putut aloca mem pt FN al membrului %d\n", j);
            char *tmp_mem_points = read(_fff_dta, 0, " \n"); if(!tmp_mem_points) fprintf(stderr, "t1:60");
            sscanf(tmp_mem_points, "%f", &(mem->points));
            free(tmp_mem_points);
        }
        addAtBeginning(hed_lst, newList_node(tem));
    }
    return hed_lst;
}