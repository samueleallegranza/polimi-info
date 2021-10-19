/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisisca in ingresso
    due array di 5 numeri interi (assumendo che l'utente
    li inserisca ordinati in ordine crescente).
    A partire da questi array si crei l'array risultato
    che contiene tutti i numeri contenuti nei due array di
    partenza, anch'esso ordinato in ordine crescente.

    > Esempio:
    Array1 = [1,3,4,9,10]
    Array2 = [2,5,6,10,11]
    Risultato = [1,2,3,4,5,6,9,10,10,11]

*/

#include <stdio.h>
#define DIM 5
#define DIM_R (DIM*2)

int main(int argc, char * argv[]) {
    int arr1[DIM];
    int arr2[DIM];
    int ord[DIM_R];

    int i;
    int x1, x2;

    printf("Insert values of list 1: \n");
    for(i=0; i<DIM; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Insert values of list 2: \n");
    for(i=0; i<DIM; i++) {
        scanf("%d", &arr2[i]);
    }

    //      First solution:
    // x1 = 0;
    // x2 = 0;
    // for(i=0; i<DIM*2; i++) {
    //     if(arr1[x1] < arr2[x2]) {
    //         ord[i] = arr1[x1];
    //         x1++;
    //     } else {
    //         ord[i] = arr2[x2];
    //         x2++;
    //     }
    // }

    x1 = 0;
    x2 = 0;
    i = 0;

    while(x1 < DIM || x2 < DIM) {
        if(x1 >= DIM) {
            ord[i] = arr2[x2];
            x2++;
        } else if (x2 >= DIM) {
            ord[i] = arr2[x1];
            x1++;
        } else {
            if(arr1[x1] <= arr2[x2]){
                ord[i] = arr1[x1];
                x1++;
            } else {
                ord[i] = arr2[x2];
                x2++;
            }
        }
        i++;
    }

    for(i=0; i<DIM_R; i++) {
        printf("%d ", ord[i]);
    }
    printf("\n");

    return 0;
}