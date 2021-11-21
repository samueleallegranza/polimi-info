#include <stdio.h>

int cat(int);

int main(int argc, char * argv[]) {
    int x, i;
    scanf("%d", &x);

    for(i=0; i<x; i++) {
        printf("C(%d) = %d\n", i, cat(i));
    }
    printf("End.\n");

    return 0;
}

int cat(int n) {
    int i, c;
    if(n == 0)
        c = 1;
    else {
        c = 0;
        for(i=0; i<=(n-1); i++) {
            c += (cat(i) * cat(n-i-1));
        }
    }
    return c;
}
