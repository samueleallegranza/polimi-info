#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR1 1
#define STR2 2

int * conta(char [], char []);

int main(int argc, char * argv[]) {
    int * res, i;
    char * cars, * info;

    if(argc >= 3) {
        info = argv[STR1];
        cars = argv[STR2];
        res = conta(info, cars);

        for(i=0; cars[i]!='\0'; i++)
            printf("%c %d\n", cars[i], res[i]);
    } else
        printf("Argc invalid.\n");

    return 0;
}

int * conta(char info[], char cars[]) {
    int * counters;
    int i, j, len, found;

    len = strlen(cars);
    counters = malloc(sizeof(int) * len);
    for(i=0; i<len; i++)
        *(counters+i) = 0;

    for(i=0; info[i]!='\0'; i++) {
        found = 0;
        for(j=0; cars[j]!='\0' && !found; j++) {
            if(info[i]==cars[j]) {
                *(counters+j) += 1;
                found=1;
            }
        }
    }

    return counters;
}
