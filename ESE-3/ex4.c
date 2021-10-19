/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che, ricevuto in ingresso un numero
    intero positivo o nullo (e nel caso il valore non e' tale
    lo richiede), calcoli e visualizzi il suo fattoriale.
*/

#include <stdio.h>

int main(int argc, char * argv[]){

    int val, fact;
    do
        scanf("%d", &val);
    while(val<0);

    fact = 1;
    while(val>1) {
        printf("x");
        fact *= val;
        val--;
    }

    printf("%d\n", fact);

    return 0;
}