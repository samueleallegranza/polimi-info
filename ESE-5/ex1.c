/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisiti al massimo
    50 numeri interi strettamente positivi (si consideri
    terminato l'inserimento quando l'utente inserisce un
    valore non valido), scambi tra loro i numeri a due a
    due presenti nell'array.
    Al termine dello scambio, il programma visualizza 
    l'array risultante. L'array risultato deve essere lo
    stesso array di partenza con i valori modificati.

    > Esempio:
        Input   [1,2,3,4,5,6,7]
        Output  [2,1,4,3,6,5,7]
*/

#include <stdio.h>
#define DIM 50

int main(int argc, char * argv[]) {

    int arr[DIM] = {1,2,3,4,5};
    int count;
    int i, tmp;

    count=0;
    scanf("%d", &tmp);
    while(tmp>0 && count<DIM) {
        arr[count] = tmp;
        count++;
        scanf("%d", &tmp);
    }

    for(i=0; i<count; i+=2) {
        if((i+1)<count) {
            tmp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tmp;
        }
    }

    for(i=0; i<count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

