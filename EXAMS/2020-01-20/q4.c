#include <stdio.h>
#include <stdlib.h>
#define START_UP 'A'
#define END_UP 'Z'
#define START_DOWN 'a'
#define END_DOWN 'z'
#define OFFSET (START_DOWN - START_UP)
#define ARGV_STR 1
#define RES_MIN 0
#define RES_MAX 1

char * minmaxstr(char []);
char * minmaxstr2(char []);

int main(int argc, char * argv[]) {
    char * res;

    if(argc >= (ARGV_STR+1)) {
        // res = minmaxstr(argv[ARGV_STR]);
        res = minmaxstr2(argv[ARGV_STR]);
        printf("min: %c\nmax: %c\n", res[RES_MIN], res[RES_MAX]);
    } else {
        printf("Argc not satisfied\n");
    }

    return 0;
}

char * minmaxstr(char str[]) {
    char * res;
    int i;
    int max, min;

    res = malloc(sizeof(char) * 2); //No space for '\0' is intentional

    min = 0;
    max = 0;
    for(i=1; str[i]!='\0'; i++) {
        if(str[i] > str[max])
            max = i;
        if(str[i] < str[min])
            min = i;
    }

    res[0] = str[min];
    res[1] = str[max];

    return res;
}

char * minmaxstr2(char str[]) {
    char * res;
    int i;
    char curr;

    res = malloc(sizeof(char) * 2);

    if(str[0]>=START_UP && str[0]<=END_UP) {
        curr = str[0] + OFFSET;
    }
    else {curr = str[0];}
    res[RES_MIN] = curr;
    res[RES_MAX] = curr;

    for(i=1; str[i]!='\0'; i++) {
        if(str[i]>=START_UP && str[i]<=END_UP) {
            curr = str[i] + OFFSET;
        }
        else {curr = str[i];}

        printf("%c%c\n", str[i], curr);

        if(curr < res[RES_MIN]) res[RES_MIN] = curr;
        if(curr > res[RES_MAX]) res[RES_MAX] = curr;
    }

    return res;
}
