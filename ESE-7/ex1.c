/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Il cifrario di Cesare e' una strategia crittografica che
    si basa sul sostituire ogni carattere di una stringa con il
    carattere che occupa 3 posizioni successive nell'alfabeto
    considerandolo in modo circolare (per trovare le corrispondenze
    delle ultime lettere dell'alfabeto).
    Le sostituzioni effettuate sono quindi le seguenti (sopra le
    lettere in chiaro, sotto le corrispondenze cifrate).

    a b c d e f g ... v w z y z
    d e f g h i j ... y z a b c

    Si scirva un programma che acquisita in ingresso una stringa
    di al massimo 50 caratteri minuscoli dell'alfabeto inglese
    (senza spazi) la cifi (modificando la stringa ricevuta in
    ingresso) usando il cifrario di Cesare.
    Si mostri poi la stringa cifrata.
*/
#include <stdio.h>
#define MAX_LEN 50
#define LETTERS 26
#define KEY 3
#define START 'x'

int main(void) {

    char str[MAX_LEN+1];
    int i;

    scanf("%s", str);

    for(i=0; str[i] != '\0'; i++) {
        str[i] = START + (((str[i] - START) + KEY ) % LETTERS);
    }

    printf("%s\n", str);

    return 0;
}