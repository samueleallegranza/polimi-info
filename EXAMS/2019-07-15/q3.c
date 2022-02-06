#include <stdio.h>
#include <stdlib.h>
#define ARG_STR 1
#define ARG_CH 2

char * crop(char[], char);

int main(int argc, char * argv[]) {
    char *res;

    if(argc >= (ARG_CH+1)) {
        res = crop(argv[ARG_STR], argv[ARG_CH][0]);
        printf("%s\n", res);
    }

    return 0;
}

char * crop(char frase[], char ch) {
    int i, start, end, occ, res_len;
    char * res;

    occ = 0;
    for(i=0; frase[i]!='\0' && occ<2; i++) {
        if(frase[i] == ch) {
            occ++;
            if(occ == 1)
                start = i+1;
            else
                end = i-1;
        }
    }


    if(occ == 2) {
        res_len = end-start;
        res = malloc(sizeof(char) * (res_len+1)); // len + 1 ('\0')
        for(i=0; i<=res_len; i++)
            *(res+i) = frase[start+i];
        *(res+i) = '\0';
        printf("%s\n", res);
    } else
        res = NULL;

    return res;
}
