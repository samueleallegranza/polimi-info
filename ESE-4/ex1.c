/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisito un numero intero
    strettamente positivo (e fino a che non e' tale lo richiede) 
    determini la parte intera della sua radice quadrata.
*/
#include <stdio.h>

int main(int argc, char * argv[]) {

    int val, rad, sqr;

    do {
        scanf("%d", &val);
    } while (val<=0);


    rad = 1;
    sqr = rad*rad;
    while(sqr <= val) {
        rad++;
        sqr = rad*rad;
    }
    rad--;

    printf("%d\n", rad);

    return 0;
}