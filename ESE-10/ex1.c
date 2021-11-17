/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un programma che dato un file contentente 1
    parola per riga chiamato dizionario.txt, chieda all'utente
    una parola da ricercare all'interno del file, e salvi in
    un secondo file di testo chiamato 'query.log' il risultato
    della ricerca nel formato:
    - 'parola: 0': se la parola non e' contenuta nel file
    - 'parola: 1': se questa e' contenuta
    ('parola' indica la parola da ricercare)
*/
#include <stdio.h>
#include <string.h>
#define FN_IN "dizionario.txt"
#define FN_OUT "query.log"
#define WORD_MAXLEN 50

int main(int argc, char * argv[]) {
    FILE * fin, * fout;
    char search[WORD_MAXLEN];
    char curr[WORD_MAXLEN];
    int found;

    if(fin = fopen(FN_IN, "r")) {
        if(fout = fopen(FN_OUT, "a")) {
            scanf("%s", search);
            found = 0;
            while(fscanf(fin, "%s", curr)!=EOF && !found) {
                if(strcmp(curr, search) == 0)
                    found = 1;
                else
                    found = 0;
            }
            fprintf(fout, "%s: %d\n", search, found);
            fclose(fout);
        } else {
            printf("Errore apertura file %s\n", FN_OUT);
        }
        fclose(fin);
    } else {
        printf("Errore apertura file %s\n", FN_IN);
    }

    return 0;
}