#include <stdio.h>
#define FN "dizionario.txt"
#define MAXLEN 35

int check_voc(char []);
int is_voc(char);

int main(int argc, char * argv[]) {
    FILE * fp;
    char word[MAXLEN + 1];

    if(fp = fopen(FN, "r")) {
        while(!feof(fp)) {
            fscanf(fp, "%s", word);
            if(check_voc(word))
                printf("%s\n", word);
        }
        fclose(fp);
    } else {
        printf("Errore apertura %s\n", FN);
    }

    return 0;
}

int check_voc(char word[]) {
    int flg, i;
    char prev_voc;

    i=0; flg = 1;
    prev_voc = -1;

    while(flg && word[i]!='\0') {
        if(is_voc(word[i])) {
            flg = word[i] >= prev_voc;
            prev_voc = word[i];
        }
        i++;
    }

    return flg;
}

int is_voc(char c) {
    return (
        c == 'a' || c == 'A' ||
        c == 'e' || c == 'E' ||
        c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' ||
        c == 'u' || c == 'U'
    );
}
