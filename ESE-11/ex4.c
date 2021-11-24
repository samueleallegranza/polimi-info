/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma ricorsivo che ricevuto in ingresso
    un numero intero restituisce la cifra piu' alta della
    rappresentazione decimale. Per esempio, se il valore ricevuto in
    ingresso e' 1232 il sottoprogramma restituisce 3.
*/
#include <stdio.h>
#include <stdlib.h>
#define BASE 10

int maxdec(int);

int main(int argc, char * argv) {
    printf("%d\n", maxdec(112309142));
}

int maxdec(int n) {
    int curr, maxsucc;

    if(n==0)
        return 0;
    if(n<0)
        n = -n;

    curr = n%BASE;
    maxsucc = maxdec(n/BASE);

    if(curr > maxsucc)
        return curr;
    else
        return maxsucc;
}
