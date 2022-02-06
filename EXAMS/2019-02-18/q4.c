#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_WORD 25
#define FN "dizionario.txt"
#define N_ALPH 'Z' - 'A'

int idx_alph(char);
int dimmianagramma(char []);
int anagramma(char [], char []);

int main(int argc, char * argv[]) {
    printf("\n\n%d\n", dimmianagramma("armi"));
    return 0;
}

int dimmianagramma(char str[]) {
    int count;
    FILE * fp;
    char word[MAX_WORD + 1];

    if(fp = fopen(FN, "r")) {
        count = 0;
        while(fscanf(fp, "%s", word) == 1) {
            if(anagramma(str, word)) {
                count++;
                printf("[%s]\n", word);
            }
        }
        fclose(fp);
    } else {
        count = -1;
    }

    return count;
}

int anagramma(char str1[], char str2[]) {
    int * counters;
    int i, pass;

    counters = malloc(sizeof(int) * N_ALPH);
    for(i=0; i<N_ALPH; i++)
        *(counters+i) = 0;

    for(i=0; str1[i]!='\0' && str2[i]!='\0'; i++) {
        *(counters+idx_alph(str1[i])) += 1;
        *(counters+idx_alph(str2[i])) -= 1;
    }

    if((str1[i]=='\0' && str2[i]!='\0') || (str2[i]=='\0' && str1[i]!='\0')) {
        pass = 0;
    } else {
        pass = 1;
        for(i=0; i<N_ALPH && pass; i++)
            pass = *(counters+i) == 0;
    }

    return pass;
}

int idx_alph(char c) {
    c = tolower(c);
    return c-'a';
}
