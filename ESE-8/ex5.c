/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma che ricevuta in ingresso
    una stringa di testo composta da soli caratteri
    dell'alfabeto inglese (maiuscoli e minuscoli) la
    faccia diventare tutta maiuscola, modificandola.
*/
#include <stdio.h>
#define FIRST_UPPER 'A'
#define FIRST_LOWER 'a'
#define LAST_LOWER 'z'

void to_upper(char []);

int main(int argc, char * argv[]) {
    char text[] = "Yesterday we made 10 brownies!.\n";
    to_upper(text);
    printf("%s", text);
    return 0;
}

void to_upper(char str[]) {
    int i;
    for(i=0; str[i] != '\0'; i++) {
        if(str[i] >= FIRST_LOWER && str[i] <= LAST_LOWER) {
            str[i] -= (FIRST_LOWER - FIRST_UPPER);
        }
    }
}
