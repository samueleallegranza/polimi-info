/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un sottoprogramma che ricevuto in ingresso
    un array di valori interi e qualsiasi altro parametro
    ritenuto strettamente necessario restituisca il
    numero di coppie di numeri uguali valide presenti.
    Una coppia di numeri uguali si dice valida se dati gli
    indici i, j dei numeri che formano la coppia,
    numero[i] == numero[j] e i<j
*/
#include <stdio.h>

int find_equals(int [], int);

int main(int argc, char * argv[]) {
    int arr[7] = {1, 1, 1, 2, 1, 3, 3};
    printf("%d\n", find_equals(arr, 5));
    return 0;
}

int find_equals(int arr[], int len) {
    int i, j, pairs;
    pairs = 0;
    for(i=0; i<len-1; i++) {
        for(j=i+1; j<len; j++) {
            if(arr[i] == arr[j])
                pairs++;
        }
    }
    return pairs;
}
