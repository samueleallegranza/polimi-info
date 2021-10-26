/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un sottoprogramma che ricevuto in ingresso
    un array di numeri reali, calcola e trasmette al
    chiamante un array di valori in cui ogni elemento
    e' dato dalla somma del corrispondente valore
    dell'array di partenza con tutti i numeri precedenti
*/
#include <stdio.h>

void progressive_sum(float [], float [], int);

int main(int argc, char * argv[]) {
    float arr[7] = {1, 1, 1, 2, 1, 3, 3};
    float res[7];
    int i;
    progressive_sum(arr, res, 7);
    for(i=0; i<7; i++) {
        printf("%4.1f   ", res[i]);
    }
    printf("\n");
    return 0;
}

void progressive_sum(float arr[], float res[], int len) {
    int i, j;
    if(len>0) {
        res[0] = arr[0];
        for(i=1; i<len; i++) {
            res[i] = res[i-1] + arr[i];
        }
    }
}
