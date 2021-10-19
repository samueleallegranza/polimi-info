/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che visualizzi la tabella pitagorica

*/

#include <stdio.h>
#define ROWS 12
#define COLUMNS 12

int main(int argc, char * argv[]) {

    int i, j;

    i=1;
    while(i<=ROWS){
        j=1;
        while(j<=COLUMNS){
            printf("%6d", j*i);
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}