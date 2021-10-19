/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un programma che, date due sequenze di numeri interi
    inseriti dall'utente, conti quanti numeri sono presenti in entrambe
    le sequenze e li mostri a schermo.

    NOTA: Si presuppone che l'utente inserisca valori tutti diversi
    tra loro per ognuna delle due liste

    > Esempio:
    Lista 1: 1 2 3 4 5
    Lista 2: 4 5 6 7 8
    Ripetuti: 2
    Valori: 4 5
*/

#include <stdio.h>
#define DIM 5

int main(void) {

    int list1 [DIM];
    int list2 [DIM];
    int equals [DIM];
    int i, j, count;

    printf("Inserisci valori prima lista\n");
    for(i=0; i<DIM; i++) {
        scanf("%d", &list1[i]);
    }

    printf("Inserisci valori prima lista\n");
    for(i=0; i<DIM; i++) {
        scanf("%d", &list2[i]);
    }

    count = 0;
    for(i=0; i<DIM; i++) {
        for(j=0; j<DIM; j++) {
            if(list1[i] == list2[j]){
                equals[count] = list1[i];
                count++;
            }
        }
    }

    // Stampo risultati
    printf("Uguali: %d\n", count);
    for(i=0; i<count; i++) {
        printf("%d ", equals[i]);
    }
    printf("\n");

    return 0;
}