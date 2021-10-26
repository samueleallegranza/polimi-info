#include <stdio.h>
#define BASE 10

int cifra(int, int);

int main(int argc, char * argv[]) {
    printf("%d\n", cifra(1425, 2));
    printf("%d\n", cifra(-9064663, 1));
    printf("%d\n", cifra(9064663, -1));
    printf("%d\n", cifra(9064663, 6));
    return 0;
}

int cifra(int n, int k) {
    int i, digit;
    digit = -1;

    if(n<0)
        n = -n;

    digit = -1;
    for(i=1; i<=k; i++) {
        digit = n%BASE;
        n /= BASE;
    }

    return digit;
}
