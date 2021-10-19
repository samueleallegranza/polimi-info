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

int main(void) {

    char str[MAX_LEN+1];
    int i, half, len, pal;

    scanf("%s", str);
    
    for(len=0; str[len] != '\0'; len++);
    // j = strlen(str);

    half = len/2;
    pal = 1;
    for(i=0; i<half && pal; i++)
        if(str[i] != str[len-i-1])
            pal = 0;

    printf("%d\n", pal);

    return 0;
}