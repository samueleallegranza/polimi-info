/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un programma che data una stringa inserita
    dall'utente, la quale consiste in due parole non separate
    da un spazio (ad esempio 'buonagiornata'), stampi le due
    parole separate da uno spazio (correttamente posizionato).
    Per capire in che punto inserire lo spazio, viene messo
    a disposizione del programma un dizionario di nome
    'dizionario.txt' contenente un elenco di parole.
    Il programma stampa la prima possibilita' trovata, ignorando
    eventuali altre soluzioni.
*/
#include <stdio.h>
#include <string.h>
#define FN_DICT "dizionario.txt"
#define WORD_MAXLEN 50

int substr(char[], char[]);

int main(int argc, char * argv[]) {
    FILE * fdict, * fdict2;
    int found, i;
    char words[WORD_MAXLEN];
    char curr1[WORD_MAXLEN];
    char curr2[WORD_MAXLEN];
    char * tmp;

    scanf("%s", words);

    if(fdict=fopen(FN_DICT, "r")) {
        if(fdict2=fopen(FN_DICT, "r")) {

            found = 0;
            while(!found && fscanf(fdict, "%s", curr1) != EOF) {
                if(substr(words, curr1)) {
                    tmp = &words[strlen(curr1)];

                    rewind(fdict2);
                    while(!found && fscanf(fdict2, "%s", curr2) != EOF) {
                        if(!strcmp(curr2, tmp)) {
                            found = 1;
                            printf("%s %s\n", curr1, curr2);
                        }
                    }
                }
            }

            fclose(fdict2);
        } else {
            printf("Errore apertura file dizionario '%s'\n", FN_DICT);
        }
    } else {
        printf("Errore apertura file dizionario '%s'\n", FN_DICT);
    }

    return 0;
}

int substr(char full[], char sub[]) {
    int i=0;
    while((sub[i] == full[i]) && (sub[i] != '\0') && (full[i] != '\0'))
        i++;
    return (sub[i] == '\0') && (full[i] != '\0');
}
