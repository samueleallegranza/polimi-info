#include <stdio.h>
#define DIM 5

void calcolaMinori(int [], int [], int);

int main(int argc, char * argv[]) {
    int vals[DIM] = {8,1,2,2,3};
    int mins[DIM];
    int i;

    calcolaMinori(vals, mins, DIM);
    for(i=0; i<DIM; i++) {
        printf("%4d", mins[i]);
    }
    printf("\n");

    return 0;
}

void calcolaMinori(int arr[], int res[], int dim) {
    int i, j, min;
    for(i=0; i<dim; i++) {
        min = 0;
        for(j=0; j<dim; j++) {
            if(arr[j] < arr[i])
                min++;
        }
        res[i] = min;
    }
}
