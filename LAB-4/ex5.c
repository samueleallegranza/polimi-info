#include <stdio.h>

int cat(int);

int main(int argc, char * argv[]) {
    int x, i;

    do {
        scanf("%d", &x);
    } while(x<0);

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
        // Piu ottimizzato:
        // for(i=0; i<n/2; i++)
        //     cn *= cat(i) * cat(n-i-1);
        // cn *= 2;
        // if(n%2 != 0)
        //     cn += cat(n/2) * cat(n-(n/2)-1);
    }
    return c;
}
