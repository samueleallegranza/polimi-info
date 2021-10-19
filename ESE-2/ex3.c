/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisiti due numeri interi
    sicuramente positivi a e b, trovi il primo numero multiplo
    di a maggiore di b.
*/

#include <stdio.h>

int main(int argc, char * argv[]) {
    
    int a,b;
    int mult;

    scanf("%d%d", &a, &b);
    
    mult = a;
    while(mult<=b) {
        mult += a;
    }

    printf("%d\n", mult);

    return 0;
}