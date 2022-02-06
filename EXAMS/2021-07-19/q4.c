#include <stdio.h>
#define FN "parole.txt"
#define NOT_SET -1
#define MAX_WORD 30

char analizza(char [], int *);

int main(int argc, char * argv[]) {
    FILE * fp;
    char resch, word[MAX_WORD+1];
    int resqt, maxqt;

    if(fp = fopen(FN, "r")) {
        maxqt = NOT_SET;
        while(fscanf(fp, "%s", word) == 1) {
            resch = analizza(word, &resqt);
            printf("%c %d\n", resch, resqt);
            if(maxqt < resqt)
                maxqt = resqt;
        }
        printf("%d\n", maxqt);
        fclose(fp);
    } else {
        printf("Errore apertura file\n");
    }

    return 0;
}

char analizza(char str[], int * count) {
    int i, maxc_idx, count_c;

    count_c = 1;
    maxc_idx = 0;
    for(i=1; str[i]!='\0'; i++) {
        if(str[i] < str[maxc_idx]) {
            maxc_idx = i;
            count_c = 1;
        } else if(str[i] == str[maxc_idx])
            count_c++;
    }

    *count = count_c;
    return str[maxc_idx];
}
