/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma che, ricevuti in ingresso
    2 array e un terzo da usare per salvare i risultati,
    oltre ad altri eventuali parametri ritenuti
    strettamente necessari, inserire nel terzo array i
    valori che sono presenti in entrambi i 2 array
    iniziali.
    Si presupponga che ogni array contenga valori diversi
    tra loro, e che l'array dei risultati sia definito di
    grandezza sufficiente (non dobbiamo preoccuparcene).
*/
#include <stdio.h>

int select_reps(int [], int, int [], int, int []);

int main(int argc, char * argv[]) {
    int a1[5] = {3, 4, 5, 1, 2};
    int a2[6] = {1, 7, 6, 5, 4, 2};
    int reps[6];
    int i, reps_len;
    reps_len = select_reps(a1, 6, a2, 6, reps);
    for(i=0; i<reps_len; i++) {
        printf("%4d", reps[i]);
    }
    printf("\n");
    return 0;
}

int select_reps(int a1[], int a1_l, int a2[], int a2_l, int reps[]) {
    int i, j, found, count;
    count = 0;
    for(i=0; i<a1_l; i++) {
        found = 0;
        for(j=0; j<a2_l && !found; j++) {
            if(a1[i] == a2[j]) {
                reps[count] = a1[i];
                count++;
                found = 1;
            }
        }
    }
    return count;
}
