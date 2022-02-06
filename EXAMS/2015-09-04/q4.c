#include <stdio.h>
#include "../../lib/listi.c"
#define DIM 6

listi_t * listlessavg(int [], int);
float arravg(int[], int);

int main(int argc, char * argv[]) {
    int nums[DIM] = {1,5,3,4,2,6};
    listi_t * h = NULL;
    h = listlessavg(nums, DIM);
    print_list(h);
    return 0;
}

listi_t * listlessavg(int arr[], int dim) {
    listi_t * h = NULL;
    float avg;
    int i;

    avg = arravg(arr, dim);
    for(i=0; i<dim; i++)
        if(arr[i] < avg)
            h = append(h, arr[i]);

    return h;
}

float arravg(int arr[], int dim) {
    int i, sum;
    float avg;
    sum = 0;
    for(i=0; i<dim; i++)
        sum += arr[i];
    return (float) sum / dim;
}
