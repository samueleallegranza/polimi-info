/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma rep che ricevuto in ingresso
    una stringa 'str' e un numero 'n' intero, ritorni al chiamante una
    nuova stringa contenente la stringa originale 'str' ripetuta
    per 'n' volte.
    Ad esempio, se la stringa in ingresso e' "bla" e 'n'=3, il
    sottoprogramma ritorna la stringa "blablabla".
    Se l'utente richiede 0 ripetizioni, torna una stringa vuota.
*/
#include <stdio.h>
#include <stdlib.h>

char * rep(char *, int);

int main(int argc, char * argv) {
    char * res;
    res = rep("rep", 0);
    printf("%s\n", res);
    return 0;
}

char * rep(char * str, int r) {
    int len, i;
    char * res;

    len=0;
    if(r > 0)      // If r=0 it's not necessary to calculate len
        for(; str[len]!='\0'; len++);

    res = malloc(sizeof(char) * ((len*r) + 1));
    if(res==NULL)
        return NULL;

    for(i=0; i<(len*r); i++)
        *(res+i) = str[i%r];
    *(res+i) = '\0';

    return res;
}
