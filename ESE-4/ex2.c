/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisiti:
        - Un valore di saldo di un conto bancario attuale
        - Un tasso di interesse che verra' applicato annualmente
          sul valore di saldo
        - Un valore di saldo di conto bancario che si desidera
          raggiungere

    Stampare dopo quanti anni si raggiungera' il valore di saldo
    desiderato 
*/
#include <stdio.h>

int main(int argc, char * argv[]) {

    float saldo, tasso, fin;
    int yrs;
    float next;

    do {
        scanf("%f", &saldo);
    } while(saldo<=0);
    do {
        scanf("%f", &tasso);
    } while(tasso<=0);
    do {
        scanf("%f", &fin);
    } while(fin<=0);

    yrs = 0;
    next = saldo;
    while(next<fin) {
        yrs++;
        next = next + next*tasso;
    }

    printf("Years: %d - Money: %.2f\n", yrs, next);

    return 0;
}