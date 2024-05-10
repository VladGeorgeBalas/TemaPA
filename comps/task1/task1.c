#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/data/data.h"
#include "../../libs/list/list.h"
#include "../../libs/list/utils.h"

char* read(FILE* _stream, unsigned int _length, const char* terminator){

    char c = getc(_stream);

    if(strchr(terminator, c))
    {
        char* result = (char*)malloc(sizeof(char) * (_length + 1));
        if(!result) return NULL;

        *(result + _length) = '\0';
        return result;
    }
    else {
        char *result = read(_stream, _length + 1, terminator);
        if (!result) return NULL;

        *(result + _length) = c;
        return result;
    }
}

extern struct list_node* task1(FILE* _fff_dta){
    //numarul de echipe
    unsigned int num_tem;
    //citire numar de echipe
    fscanf(_fff_dta, "%d", &num_tem);

    //initializare lista
    struct list_node* hed_lst = newList();

    //pentru fiecare dintre echipe
    for(unsigned int i = 1; i <= num_tem; i++)
    {
        struct team* tem = (struct team*)malloc(sizeof(struct team));
        if(!tem) fprintf(stderr, "Esec alocare memorie pt echipa nr %d", i);

        //numarul de membri
        unsigned int num_mem;
        //citim numarul de membri
        //fscanf(_fff_dta, "%d", &num_mem);
        char* _num_mem = read(_fff_dta, 0, " ");
        sscanf(_num_mem, "%d", &num_mem);
        free(_num_mem);

        //initializam vectorul de coechipieri
        struct player* tem_mem = (struct player*)malloc(sizeof(struct player) * num_mem);
        //eroare daca nu s-a putut aloca memoria
        if(!tem_mem) fprintf(stderr, "Nu s-a putut aloca memorie pentru membri pentru echipa nr %d\n", i);
        else fprintf(stderr, "S-a alocat mem pentru membrii echipei %d, nr mem %d\n", i, num_mem);

        //citire si alocare nume echipa
        tem->name = read(_fff_dta, 0, "\n");
        //eroare daca nu s-a putut aloca memoria
        if(!tem->name) fprintf(stderr, "Nu s-a putut aloca memorie pentru nume pentru echipa nr %d\n", i);
        else fprintf(stderr, "s-a alocat mem pt nume : %s\n", tem->name);

        //pentru fiecare membru al echipei
        for(int j = 0; j < num_mem; j = j + 1)
        {
            //selectam membrul echipei
            struct player* mem = tem_mem + j;

            mem->last_name = read(_fff_dta, 0, " \n");
            if(!mem->last_name) fprintf(stderr, "   Nu s-a putut aloca mem pt LN al membrului %d\n", j);
            else fprintf(stderr, "  s-a alocat mem pt LN al membrului %d : %s\n", j, mem->last_name);

            mem->first_name = read(_fff_dta, 0, " \n");
            if(!mem->last_name) fprintf(stderr, "   Nu s-a putut aloca mem pt FN al membrului %d\n", j);
            else fprintf(stderr, "  s-a alocat mem pt FN al membrului %d : %s\n", j, mem->first_name);

            char* tmp_mem_points = read(_fff_dta, 0, " \n");
            sscanf(tmp_mem_points, "%d", &(mem->points));
            fprintf(stderr, "  s-a alocat mem pt nr pct al mem %d : %d\n\n", j, mem->points);
            free(tmp_mem_points);
        }

        addAtBeginning(hed_lst, newList_node(tem));
    }

    return hed_lst;
}