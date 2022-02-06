#include <stdio.h>
#define BASE 10

int digit_divisors(int);

int main(int argc, char * argv[]) {

    printf("%d\n", digit_divisors(12));
    printf("%d\n", digit_divisors(1012));
    printf("%d\n", digit_divisors(0));
    printf("%d\n", digit_divisors(3333));

    return 0;
}

int digit_divisors(int v) {
    int count, d, curr;

    count = 0;
    curr = v;
    while(curr>0) {
        d = curr%BASE;
        if(d!=0)
            if(v%d==0)
                count++;
        curr/=BASE;
    }

    return count;
}
