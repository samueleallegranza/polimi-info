/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che acquisiti due numeri interi
    sicuramente positivi a e b, trovi il primo numero multiplo
    di a maggiore di b.

    SOLUZIONE 2
*/

#include <stdio.h>

int main(int argc, char * argv[]) {
    
    int a,b;
    int mult;

    scanf("%d%d", &a, &b);

    /*
        calcolo del multiplo "matematico"
        Esempio:
            a=9, b=9        Valori iniziali
            a/b = 1         Qunti multipli ci sono tra b e a
            (1)+1 = 2       Aggiungo 1 per andare al successivo
            (2)*a = 18      Trovo il multiplo effettivo corrispondente
    */
    mult = ((b/a)+1)*a;
    
    printf("%d\n", mult);

    return 0;
}