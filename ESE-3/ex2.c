/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisiti due numeri interi positivi
    a e b (e finche' non sono tali li richiede), calcoli e visualizzi
    l'MCD e l'mcm
*/

#include <stdio.h>

int main(int argc, char * argv) {

    int a, b;
    int mcd, mcm;

    do
        scanf("%d", &a);
    while(a<=0);
    do
        scanf("%d", &b);
    while(b<=0);

    // Ricerca MCD
    if(a < b) {
        mcd = a;
    } else {
        mcd = b;
    }

    while(a%mcd != 0 || b%mcd != 0)
        mcd--;

    // Ricerca mcm
    mcm = (a*b)/mcd;

    printf("mcd:%d\tmcm:%d\n", mcd, mcm);

    return 0;
}