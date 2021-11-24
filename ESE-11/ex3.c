/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma (con tutti i parametri che si
    ritengono necessari) che istanzia, riempe, e ritorna al
    chiamante un array di numeri interi.
    Il sottoprogramma deve prima richiedere all'utente quanti
    elementi questo vuole inserire e poi procedere con la loro
    acquisizione.

*/
#include <stdio.h>
#include <stdlib.h>

int * scan_array(int *);

int main(int argc, char * argv[]) {
    int * res;
    int count, i;
    res = scan_array(&count);
    for(i=0; i<count; i++) {
        printf("%d\t", res[i]);
    }
    printf("\n");
}

int * scan_array(int * count) {
    int i;
    int *res;

    scanf("%d", count);
    res = malloc(sizeof(int) * (*count));
    if(res) {
        for(i=0; i<(*count); i++)
            scanf("%d", &res[i]);
    }

    return res;
}
