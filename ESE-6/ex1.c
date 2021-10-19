/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisiti in ingresso
    10 valori interi ed un ulteriore numero intero
    che rappresenta una quantita' obiettivo da raggiungere,
    determini se tra i 10 valori acquisiti esista almeno
    una coppia di valori che sommati tra loro dia come
    risultato il numero inserito.
    Si assuma che tra i valori inseriti non compaiano
    valori riptetuti. Si visualizzi 1 in caso esista tale
    coppia di valori, 0 altrimenti.

    > Esempio:
        Input   [0,1,0,2,-3,5], 6
        Output  1
*/
#include <stdio.h>
#define DIM 10

int main(void) {

    int obj;
    int num[DIM];
    int i, j, found;

    for(i=0; i<DIM; i++) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &obj);
 
    found = 0;
    for(i=0; i<DIM-1 && !found; i++) {
        for(j=i+1; i<DIM && !found; i++){
            if(num[i]+num[j] == obj)
                found = 1;
        }
    }

    printf("%d\n", found);

    return 0;
}