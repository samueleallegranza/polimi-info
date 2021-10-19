/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che chieda all'utente di inserire 3
    numeri e determini se questi sono i lati di un triangolo
    rettangolo.
    Si visualizzi quindi 1 in caso affermativo, 0 altrimenti.

    Un triangolo rettangolo soddisfa il teorema di Pitagora:
    (ipotenusa)^2 = (cateto1)^2 + (cateto2)^2
*/

#include <stdio.h>

int main(int argc, char * argv[]) {

    int a, b, c;
    int res;

    scanf("%d%d%d", &a, &b, &c);

    if(a>0 && b>0 && c>0)
        // Valori accettati, controllo se terna pitagorica
        if(
            a*a == b*b + c*c ||
            b*b == a*a + c*c ||
            c*c == a*a + b*b
        )
            res = 1;
        else
            res = 0;
    else
        // Valori non accettati
        res = 0;

    printf("%d\n", res);

    return 0;
}   