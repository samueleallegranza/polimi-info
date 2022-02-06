#include <stdio.h>

int cat(int);

int main(int argc, char * argv[]) {
    int x, i;

    do{
        scanf("%d", &x);
    } while(x<=0);

    for(i=0; i<(x+1); i++)
        printf("C[%d]: %d\n", i, cat(i));

    return 0;
}

int cat(int n) {
    int c, i;
    if(n==0)
        c=1;
    else
        c=0;
        for(i=0; i<n; i++)
            c+= cat(i)*cat(n-i-1);

    return c;
}
