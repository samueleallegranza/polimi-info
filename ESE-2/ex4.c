/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisito un numero intero
    visualizzi la somma delle sue cifre

    > Esempi:
    0 ->    0
    18 ->   9
    -137 -> 11
*/

#include <stdio.h>

int main(int argc, char * argv[]){

    int val;
    int sum;

    scanf("%d", &val);

    // Portiamo numeri negativi in positivi
    if(val<0) {
        val = -val;
    }

    /*
        > Trovo la somma delle cifre

        Spiegazione algoritmo con esempio (numero 137)
            137%10 = 7      <-- sum = 7
            137/10 = 13     

            13%10 = 3       <-- sum = 7+3 = 10
            13/10 = 1

            1%10 = 1        <-- sum = 10+1 = 11
            1/10 = 0        <-- End!
    */

    sum = 0;
    while(val>0) {
        sum += val%10;
        val /= 10;
    }

    printf("%d\n", sum);

    return 0;
}