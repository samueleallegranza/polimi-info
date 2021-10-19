/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisice un array
    bi-dimensionale quadrato di dimensione 4x4 di numeri
    interi.
    Terminata l'acquisizione il programma calcola e
    visualizza 1 se i valori sulla diagonale sono
    strettamente crescenti, 0 altrimenti. 
*/

#include <stdio.h>
#define DIM 4

int main(int argc, char * argv[]) {
    
    int mat[DIM][DIM];
    int i,j, pre;
    int res;

    for(i=0; i<DIM; i++) {
        for(j=0; j<DIM; j++) {
            scanf("%d", &mat[i][j]);
        }
    }


    pre = mat[0][0];
    i = 1;
    res = 1;
    while(i<DIM && res==1) {
        if(mat[i][i] <= pre) {
            res = 0;
        }
        pre = mat[i][i];
        i++;
    }

    printf("%d\n", res);

    return 0;
}