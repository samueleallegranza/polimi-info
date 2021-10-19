/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisito un numero
    intero visualizzi la somma delle sue cifre.

    > Esempi:
    18 -> 9
    -137 -> 11
*/

#include <stdio.h>

int main(int argc, char * argv[]) {

    int val, sum;
    scanf("%d", &val);

    // Assoluto del valore
    if(val < 0)
        val = -val;

    sum = 0;
    while(val>0) {
        sum += val%10;
        val /= 10;
    }

    printf("%d\n", sum);

    return 0;
}