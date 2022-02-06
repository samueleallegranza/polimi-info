#include <stdio.h>
#define DIM 7

void quartili(int [], int, float *, float *, float *);

int main(int argc, char * argv[]) {
    int vals[DIM] = {2, 2, 2, 1, 1, 1, 1};
    float q1, q2, q3;

    quartili(vals, DIM, &q1, &q2, &q3);
    printf("%.2f\t%.2f\t%.2f\n", q1, q2, q3);
    return 0;
}

void quartili(int arr[], int dim, float * q1, float * q2, float * q3) {
    int half2, half, maxi, tmp;
    int i, j;

    // sort array
    for(i=0; i<(dim-1); i++) {
        maxi = i;
        for(j=i+1; j<dim; j++) {
            if(arr[j] < arr[maxi])
                maxi = j;
        }
    }

    tmp = arr[i];
    arr[i] = arr[maxi];
    arr[maxi] = tmp;

    // search quartiles
    half = dim/2;
    if((dim%2) == 0) {
        i = half;
        j = half-1;
        *(q1) = ((float) arr[i]+arr[j])/2;
    } else {
        *(q1) = arr[half];
    }
    half2 = dim/4;
    if(dim%4 == 0) {
        i = half;
        j = half-1;
        *(q2) = ((float) arr[i]+arr[j])/2;
        *(q3) = ((float) arr[half+j]+arr[half+i])/2;
    } else {
        *(q2) = arr[half2];
        *(q3) = arr[half+half2];
    }
}
