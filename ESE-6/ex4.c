/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisiti in ingresso
    un array bidimensionale di dimensione 4 (esattamente)
    visualizzi 1 se e' una matrice triangolare superiore,
    0 altrimenti.
    Si ricorda che una matrice si dice triangolare superiore
    se tutti gli elementi al di sotto della sua diagonale
    principale sono nulli.
*/

#include <stdio.h>
#define DIM 4

int main(int argc, char * argv[]) {
    int i,j;
    int mat[DIM][DIM];
    int triang;

    for(i=0; i<DIM; i++) {
        for(j=0; j<DIM; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    triang = 1;
    for(i=1; i<DIM && triang; i++){
        for(j=0; j<i && triang; j++) {
            if(mat[i][j] != 0) {
                triang = 0;
            }
        }
    }

    printf("%d\n", triang);

    return 0;
}