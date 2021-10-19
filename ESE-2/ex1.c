/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un programma che acquisito un numero intero viusalizzi
    1 se pari, oppure 0 se dispari.
*/

#include <stdio.h>

int main(int argc, char * argv[]) {
    // Variabili
    int val, res;

    // Acquisizione
    scanf("%d", &val);

    // Controllo numero
    if(val%2 == 0)
        res = 1; // pari
    else
        res = 0; // dispari

    // NOTA: soluzione single-line
    // res = !(numero%2);

    // Mostra risultato
    printf("%d\n", res);

    return 0;
}