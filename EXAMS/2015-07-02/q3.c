#include <stdio.h>
#define NUM_DIG 2
#define BASE 10

int specialmult(int, int[], int);
int onlydigits(int, int[], int);

int main(int argc, char * argv[]) {
    int val;
    int digits[NUM_DIG] = {0, 9};

    scanf("%d", &val);
    printf("%d\n", specialmult(val, digits, NUM_DIG));

    return 0;
}

int specialmult(int val, int digits[], int ndigits) {
    int i, mult;

    i=1;
    do {
        mult = val*i;
        i++;
    } while(!onlydigits(mult, digits, ndigits));

    return mult;
}

int onlydigits(int v, int dig[], int nd) {
    int curr;
    int ok, flag, i;

    ok = 1;
    while(v>0 && ok){
        curr = v%10;
        flag = 0;
        for(i=0; i<nd && !flag; i++)
            if(dig[i] == curr)
                flag = 1;
        printf("%d - %d\t", curr, ok);
        ok = flag;
        v /= 10;
    }

    return ok;
}
