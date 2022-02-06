#include <stdio.h>
#include <stdlib.h>
#define DIM 5

float * floating_avg(int [], int, int);
float avg_subvector(int [], int, int);

int main(int argc, char * argv[]) {
    int vals[DIM] = {10, 2, 4, 8, 4};
    float * avgs;
    int i;

    avgs = floating_avg(vals, DIM, 3);
    for(i=0; i<DIM; i++)
        printf("%.2f\t", *(avgs+i));
    printf("\n");

    return 0;
}

float * floating_avg(int arr[], int dim, int n){
    int i, start;
    float * res;

    res = malloc(sizeof(float) * dim);
    for(i=0; i<dim; i++) {
        if(i<(n-1))
            start = 0;
        else
            start = i-n+1;
        *(res+i) = avg_subvector(arr, start, i);
    }

    return res;
}

float avg_subvector(int arr[], int start, int end) {
    int sum, qt, i;

    qt = 0;
    sum = 0;
    for(i=start; i<(end+1); i++) {
        sum += arr[i];
        qt++;
    }

    return (float) sum / qt;
}
