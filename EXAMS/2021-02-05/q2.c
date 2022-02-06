#include <stdio.h>
#define DIM 6

int baricentro(int [], int);

int main(int argc, char * argv[]) {
    int vals[DIM] = {0, 0, 100, 50, 50, 0};
    printf("%d\n", baricentro(vals, DIM));
    return 0;
}

int baricentro(int arr[], int dim) {
    int sum_lf, sum_rt;
    int found, i, x;

    found = 0;
    for(i=0; i<dim && !found; i++) {
        sum_lf = 0;
        sum_rt = 0;
        for(x=0; x<=i; x++)
            sum_lf += arr[x];
        for(; x<dim; x++)
            sum_rt += arr[x];
        found = sum_rt == sum_lf;
    }

    if(!found)
        i = -1;
    else
        i--;

    return i;
}
