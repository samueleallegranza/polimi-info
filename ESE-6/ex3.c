/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisiti in ingresso
    un array bidimensionale di interi di dimensioni
    massime 50x50, determini l'indice della riga in cui
    la somma dei valori della riga e' massima.
    L'utente sceglie le dimensioni dell'array per questo
    problema ed il programma deve continuare a chiederle
    fino a quando queste non sono valide (comprese tra
    1 e 50).
*/

#include <stdio.h>
#define DIM_MAX 50

int main(int argc, char * argv[]) {

    int mat[DIM_MAX][DIM_MAX];
    int r,c;
    int i, j;
    int max_n, max_i, pre_n;

    do {
        scanf("%d", &r);
    } while(r<1 || r>50);
    do {
        scanf("%d", &c);
    } while(c<1 || c>50);


    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    max_i=0;
    max_n=0;
    for(i=0; i<c; i++) {
        max_n += mat[0][i];
    }

    for(i=1; i<r; i++) {
        pre_n = 0;
        for(j=0; j<c; j++) {
            pre_n += mat[i][j];           
        }
        if(pre_n > max_n) {
            max_n = pre_n;
            max_i = i;
        }
    }

    printf("%d\n", max_i);

    return 0;
}