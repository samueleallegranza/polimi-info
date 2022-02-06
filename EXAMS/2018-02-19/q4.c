#include <stdio.h>
#include <stdlib.h>
#define ARG_STR 1
#define ARG_REP 2

char * copy_rep(char [], int);

int main(int argc, char * argv[]) {
    char * res;

    if(argc >= (ARG_REP+1)) {
        res = copy_rep(argv[ARG_STR], atoi(argv[ARG_REP]));
        printf("%s\n", res);
    }

    return 0;
}

char * copy_rep(char s[], int n) {
    int d, newd, i;
    char * new;

    for(d=0; s[d]!='\0'; d++);
    newd = n*d;
    new = malloc(sizeof(char) * (newd+1));

    for(i=0; i<newd; i++)
        *(new+i) = s[i%d];
    *(new+i) = '\0';

    return new;
}
