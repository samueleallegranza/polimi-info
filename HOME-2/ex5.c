#include <stdio.h>

int coprimi(int, int);

int main(int argc, char * argv[]) {
    printf("%d\n", coprimi(6,35));      // yes
    printf("%d\n", coprimi(6,27));      // no
    printf("\n");

    printf("%d\n", coprimi(1,0));       // yes
    printf("%d\n", coprimi(1,1));       // yes
    printf("%d\n", coprimi(1,999));     // yes
    printf("\n");

    printf("%d\n", coprimi(0,0));       // no
    printf("%d\n", coprimi(0,1));       // yes
    printf("%d\n", coprimi(0,2));       // no
    printf("%d\n", coprimi(0,999));     // no
    printf("\n");

    return 0;
}

int coprimi(int a, int b) {
    int min, div, coprimi;

    if((a==0 || b==0) && !(a==1 || b==1)) {
        // one number is 0 and the other is different from 1
        coprimi = 0;
    } else {
        if(a<b) min = a;
        else min = b;

        coprimi = 1;
        div = 2;
        while(coprimi && div<min) {
            coprimi = a%div != b%div;
            div++;
        }
    }

    return coprimi;
}
