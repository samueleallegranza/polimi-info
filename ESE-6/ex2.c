/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisiti in ingresso
    10 valori interi ed un ulteriore numero intero
    che rappresenta una quantita' obiettivo da raggiungere,
    determini il numero di coppie distinte di valori che
    sommate tra loro dia come risultato il numero obiettivo
    inserito.
    Una coppia e' diversa da un'altra se contiene valori
    diversi indipendentemente dall'ordine in cui questi
    sono presi. Si assuma che tra i valori inseriti non
    compaiano valori ripetuti. Si visualizzi il numero
    di coppie trovate.

    > Esempio:
        Input   [-1 0 12 -3 5 -2 47 14 3 4], 9
        Output  2 (le coppie sono [12, -3], [5, 4])
*/
#include <stdio.h>
#define DIM 10

int main(void) {

    int obj;
    int num[DIM];
    int i, j, count;

    for(i=0; i<DIM; i++) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &obj);
 
    count = 0;
    for(i=0; i<DIM-1; i++) {
        for(j=i+1; i<DIM; i++){
            if(num[i]+num[j] == obj){
                count++;
            }
        }
    }

    // Nota, se volessi considerare le coppie senza tener conto
    // dell'ordine, moltiplico semplicemente il conteggio per due

    printf("%d\n", count);

    return 0;
}