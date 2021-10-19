/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Una stringa si definisce palindroma se letta al contrario
    e' identica a se stessa.
    Si scriva un programma che acquisita in ingresso una
    stringa di al massimo 50 caratteri (minuscoli dell'alfabeto
    inglese, senza spazi) determini se questa e' palindroma.
    Si stampi 1 in caso positivo, 0 altrimenti.

    > Esempio
        ara -> 1
        casa -> 0
*/
#include <stdio.h>
#define MAX_LEN 50
#define POSITIONS 1

int main(void) {

    char str[MAX_LEN+1];
    char prev, tmp;
    int i, len;

    scanf("%s", str);
    
    prev = str[0];
    for(i=1; str[i] != '\0'; i++) {
        tmp = str[i];
        str[i] = prev;
        prev = tmp;    
    }
    str[0] = prev;

    printf("%s\n", str);

    return 0;
}