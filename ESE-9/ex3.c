/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    [Consegna mancante]
*/
#include <stdio.h>
#define FNAME_MAX 80
#define NUM_START '0'
#define NUM_END '9'

int main(int argc, char * argv[]) {
    FILE * fin;
    char filename[FNAME_MAX];

    char curr;
    int count, isNumber;

    scanf("%s", filename);

    if(fin = fopen(filename, "r")) {
        count = 0;
        isNumber = 0;
        while(fscanf(fin, "%c", &curr) != EOF) {
            if(isNumber == 1 && (curr<NUM_START || curr>NUM_END)) {
                isNumber = 0;
                count++;
            } else if (isNumber == 0 && (curr>=NUM_START || curr<=NUM_END)) {
                isNumber = 1;
            }
        }
        fclose(fin);
        count += isNumber;
        printf("%d\n", count);
    } else {
        printf("Errore apertura file %s", filename);
    }

    return 0;
}
