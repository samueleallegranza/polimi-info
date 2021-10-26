#include <stdio.h>
#define DIM 10
#define NEG 0
#define PERF 1
#define ABB 2
#define DEF 3

int check_perfect(int);

int main(int argc, char * argv[]) {
    int values[DIM] = {12, 28, -1, 0, 6, 10, 18, -8, 0 ,5};
    int res[DIM];
    int i, curr;
    int neg_c, perf_c, abb_c, def_c;

    neg_c, perf_c, abb_c, def_c=0;
    for(i=0; i<DIM; i++) {
        curr = check_perfect(values[i]);
        res[i] = curr;
        if(curr == NEG)
            neg_c++;
        else if(curr == PERF)
            perf_c++;
        else if(curr == ABB)
            abb_c++;
        else if(curr == DEF)
            def_c++;
    }

    for(i=0; i<DIM; i++) {
        printf("%4d", res[i]);
    }
    printf("\n");

    printf("%d %d %d\n", perf_c, abb_c, def_c);

    return 0;
}

int check_perfect(int n) {
    int i, res, sum, half;

    if(n > 0) {
        half = n/2;
        for(sum=0, i=1; i<=half; i++)
            if(!(n%i))
                sum += i;
        if(sum == n)
            res = PERF;
        else if (sum > n)
            res = ABB;
        else
            res = DEF;
    } else
        res = NEG;

    return res;
}
