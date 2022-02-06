#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD 30
#define ARG_WORD 1
#define FILENAME "dizionario.txt"

typedef struct slista_s {
    char word[MAX_WORD+1];
    struct slista_s * next;
} slista_t;

slista_t * calcolaalternative(char [], FILE *);
slista_t * push(slista_t *, char []);
int print_list(slista_t *);

int main(int argc, char * argv[]) {
    slista_t * words = NULL;
    FILE * fp;
    int count;

    if(argc >= (ARG_WORD+1)) {
        if(fp=fopen(FILENAME, "r")) {
            words = calcolaalternative(argv[ARG_WORD], fp);
            count = print_list(words);
            printf("%d alternative\n", count);
            fclose(fp);
        } else {
            printf("Errore apertura file\n");
        }
    }

    return 0;
}

slista_t * calcolaalternative(char str[], FILE * fp) {
    int count, eq, i;
    char * word;
    slista_t * l = NULL;

    count = 0;
    if(word = malloc(sizeof(char) * (MAX_WORD+1))) {
        while(fscanf(fp, "%s", word) == 1) {
            if(str[0] != word[0]) {
                eq = 1;
                for(i=1; str[i]!='\0' && word[i] != '\0' && eq; i++)
                    eq = (str[i] == word[i]);
                if(eq && str[i]=='\0' && word[i]=='\0') {
                    count++;
                    l = push(l, word);
                }
            }
        }
    }

    return l;
}

slista_t * push(slista_t * h, char s[]) {
    slista_t * tmp;

    if(tmp = malloc(sizeof(slista_t))) {
        strcpy(tmp->word, s);
        tmp->next = h;
        h = tmp;
    } else
        printf("Errore di allocazione\n");

    return h;
}

int print_list(slista_t * h) {
    int i;

    for(i=0; h; i++){
        printf("%s\n", h->word);
        h = h->next;
    }

    return i;
}
