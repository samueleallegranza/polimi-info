#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cercacerniera(char [], char []);
char * cerniera(char [], char [], int);

int main(int argc, char * argv[]) {
    char * res;
    int cern, start;

    if(argc >= 3) {
        cern = cercacerniera(argv[1], argv[2]);
        if(cern != -1) {
            start = strlen(argv[2]) - cern;
            res = cerniera(argv[1], argv[2], start);
            printf("%s\n", res);
        }
    }

    return 0;
}

int cercacerniera(char s1[], char s2[]) {
    int len1, len2, len;
    int idx, cl, i, ok;

    len1 = strlen(s1);
    len2 = strlen(s2);
    if(len1 > len2)
        len = len2;
    else
        len = len1;

    idx = -1;
    for(cl=len; cl>0 && idx==-1; cl--) {
        ok = 1;
        for(i=0; i<cl && ok; i++){
            if(s1[i] != s2[len2-cl+i])
                ok = 0;
        }
        if(ok==1 && len2!=cl)
            idx = len2 - cl;
    }

    return idx;
}


char * cerniera(char s1[], char s2[], int inizio) {
    int len1, len2, copied, newlen, i;
    char * new;

    len1 = strlen(s1);
    len2 = strlen(s2);
    newlen = (len1+len2-(inizio*2));
    new = malloc(sizeof(char) * (newlen+1));

    if(new) {
        copied = 0;
        for(i=inizio; s1[i]!='\0'; i++) {
            *(new+copied) = s1[i];
            copied++;
        }

        for(i=0; copied<newlen; i++) {
            *(new+copied) = s2[i];
            copied++;
        }
        *(new+copied) = '\0';
    }

    return new;
}
