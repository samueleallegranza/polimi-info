#include <stdio.h>
#define MAXDIM 200
#define SPACE ' '

int conta(char []);

int main(int argc, char * argv[]) {
    printf("%d\n", conta("Prova di collaudo del programma che ho appena fatto per vedere se funziona"));
    printf("%d\n", conta("accipicchia quasi non mi accorgo di questa casistica per verificare che tutto funzioni"));
    printf("%d\n", conta("effettivamente"));
    printf("%d\n", conta("questa frase e un poco piu’ lunga delle altre per poter avere piu’ vocaboli con doppie e assicurarsi che non ci siano particolari casistiche che mandano il programma in errore durante la sua esecuzione"));
    return 0;
}

int conta(char str[]) {
    int i, prev, reps, found;

    reps = 0;
    i=0;
    while(str[i] != '\0') {
        prev = str[i];
        i++;
        found = 0;
        while(str[i]!=SPACE && str[i]!='\0' && !found) {
            if(str[i] == prev) {
                reps++;
                found = 1;
            }
            prev = str[i];
            i++;
        }
        /* vai fino al prossimo spazio / terminatore */
        for(;str[i]!=SPACE && str[i]!='\0'; i++);
    }

    return reps;
}
