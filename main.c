#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    //extrgere fisiere
    FILE* file_cerinte = fopen(*(argv + 1), "r");
    FILE* file_date = fopen(*(argv + 2), "r");
    FILE* file_iesire = fopen(*(argv + 3), "w");

    fprintf(file_iesire, "Hello world");

    fclose(file_cerinte);
    fclose(file_date);
    fclose(file_iesire);

    return 0;
}