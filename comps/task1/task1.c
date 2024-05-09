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

    struct list_node* hed_lst = newList();

    //pentru fiecare dintre echipe
    for(unsigned int i = 1; i <= num_tem; i++)
    {
        //numarul de membri
        unsigned int num_mem;
        //citim numarul de membri
        fscanf(_fff_dta, "%d", &num_mem);

        //initializam vectorul de coechipieri
        struct player* tem_mem = (struct player*)malloc(sizeof(struct player) * num_mem);
        //eroare daca nu s-a putut aloca memoria
        if(!tem_mem) fprintf(stderr, "Nu s-a putut aloca memorie pentru membri pentru echipa nr %d\n", i);

        //citire si alocare nume echipa
        char* tem_nam = read(_fff_dta, 0, "\n");
        //eroare daca nu s-a putut aloca memoria
        if(!tem_nam) fprintf(stderr, "Nu s-a putut aloca memorie pentru nume pentru echipa nr %d\n", i);

        //pentru fiecare membru al echipei
        for(unsigned int j = 0; j < num_mem; j++)
        {
            //selectam membrul echipei
            struct player* mem = tem_mem + j;

            mem->last_name = read(_fff_dta, 0, " \n");
            mem->first_name = read(_fff_dta, 0, " \n");
            fscanf(_fff_dta, "%d", &mem->points);
        }

        struct team* tem = (struct team*)malloc(sizeof(struct team));
        if(!tem) fprintf(stderr, "Esec alocare memorie pt echipa nr %d", i);

        addAtEnd(hed_lst, newList_node(tem));
    }

    return hed_lst;
}