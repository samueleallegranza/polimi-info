#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * conta(char *, char *);
int instring(char, char *);

int main(int argc, char * argv[]) {
    char info[] = "TTGCAACAGCCTTAACAGCTTTGAATGACATGGGAAAGGTAAGAAA";
    char cars[] = "ACGT";
    int * res, i;

    res = conta(info, cars);
    for(i=0; cars[i]!='\0'; i++)
        printf("%d ", res[i]);

    return 0;
}

int * conta(char * info, char * cars) {
    int cars_len, i, index;
    int * res;

    cars_len = strlen(cars);
    res = malloc(sizeof(int) * cars_len);

    for(i=0; info[i]!='\0'; i++) {
        index = instring(info[i], cars);
        if(index != -1){
            (*(res+index))++;
        }
    }

    return res;
}

int instring(char c, char * str) {
    int instr, i;
    instr = 0;
    for(i=0; str[i]!='\0' && !instr; i++)
        instr = (c==str[i]);
    i--;

    if(str[i]=='\0')
        return -1;
    else
        return i;
}
