/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma crop che ricevuta in ingresso
    una stringa frase ed un carattere 'ch' restituisce una
    nuova stringa che contiene i caratterei compresi tra la
    prima e la seconda occorrenza del carattere 'ch', ecluso
    il carattere 'ch'.
    Per esempio, se il sottoprogramma riceve in ingresso
    "informatica" e 'i', il sottoprogramma restituisce la
    stringa "nfromat".
    Nel caso in cui la stringa frase non contenga due occorrenze
    del carattere ch, restituisce NULL.
*/
#include <stdio.h>
#include <stdlib.h>

char * crop(char * string, char c);

int main(int argc, char * argv[]) {
    char * res;
    char string[] = "informatica";
    char c = 'i';

    res = crop(string, c);
    printf("%s\n", res);

    return 0;
}

char * crop(char * str, char c) {
    int i, start, stop;
    char * res;

    start=-1;
    stop=-1;
    for(i=0; str[i]!='\0' && (start==-1 || stop==-1); i++) {
        if(str[i] == c) {
            if(start == -1)
                start = i+1;
            else
                stop = i-1;
        }
    }

    if(start==-1 || stop==-1)
        return NULL;

    res = malloc(((stop-start)+1+1)*sizeof(char));
    for(i=start; i<=stop; i++)
        *(res+(i-start)) = str[i];
    *(res+(stop-start+1)) = '\0';

    return res;
}
