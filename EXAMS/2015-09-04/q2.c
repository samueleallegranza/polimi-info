#include <stdio.h>
#define BASE 10

int revint(int);

int main(int argc, char * argv[]){
    int n = 123460;
    printf("%d -> %d\n", n, revint(n));
    return 0;
}

int revint(int n) {
    int rev;

    rev = 0;
    while(n>0){
        rev = (rev*BASE) + (n%BASE);
        n /= BASE;
    }

    return rev;
}
