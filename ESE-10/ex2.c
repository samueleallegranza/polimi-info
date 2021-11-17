/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un programma che, acquisiti i nomi di due file,
    li confronti carattere per carattere e conti il numero
    di caratteri uguali.
    Il programma stampa il nome del file con meno caratteri al
    suo interno, seguito dal numero di caratteri uguali.
    Se il numero di caratteri dei due file e' uguale stampa
    '---' al posto del nome del file.
*/
#include <stdio.h>
#define FN_MAXLEN 50

int main(int argc, char * argv[]) {
    FILE * f1, * f2;
    char c1, c2;
    char fn_1[FN_MAXLEN];
    char fn_2[FN_MAXLEN];
    int equal;

    scanf("%s", fn_1);
    scanf("%s", fn_2);

    if(f1 = fopen(fn_1, "r")) {
        if(f2 = fopen(fn_2, "r")) {

            fscanf(f1, "%c", &c1);
            fscanf(f2, "%c", &c2);
            while(!feof(f1) && !feof(f2)) {
                if(c1 == c2)
                    equal++;
                fscanf(f1, "%c", &c1);
                fscanf(f2, "%c", &c2);
            }

            if(feof(f1) && feof(f2)) {
                printf("--- ");
            } else if(feof(f1)) {
                printf("%s ", fn_1);
            } else {
                printf("%s ", fn_2);
            }

            printf("%d\n", equal);

            fclose(f1);
            fclose(f2);
        } else {
            printf("Errore apertura file %s\n", fn_2);
        }
    } else {
        printf("Errore apertura file %s\n", fn_1);
    }

    return 0;
}
