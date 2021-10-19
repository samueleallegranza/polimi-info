/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un programma che crei la tavola pitagorica
    (11 righe e 11 colonne). Per ogni elemento in
    posizione (i,j) della tavola pitagorica, questa
    contiene il prodotto i*j. Si stampi poi la tavola
    pitagorica generata.
    La tavola pitagorica generata ha la prima riga e la
    prima colonna formata da zeri. Come si puo' modificare
    il programma in modo che non compaiano la prima riga e
    la prima colonna? L'array bidimensionale deve essere
    quindi di dimensione 10x10.
*/

#include <stdio.h>
#define DIM 10

int main(int argc, char * argv[]) {

    int pitag[DIM][DIM];
    int i, j;

    for(i=0; i<DIM; i++) {
        for(j=0; j<DIM; j++) {
            pitag[i][j] = (i+1)*(j+1);
        }
    }

    for(i=0; i<DIM; i++) {
        for(j=0; j<DIM; j++) {
            printf("%4d ", pitag[i][j]);
        }
        printf("\n");
    }

    return 0;
}