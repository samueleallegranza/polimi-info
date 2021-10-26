#include <stdio.h>
#define DIM 5

int rimuoviDuplicati(int [], int [], int);

int main(int argc, char * argv[]) {
    int elements[DIM] = {1, 3, 3, 7, 8};
    int reduced[DIM];
    int i, new_dim;

    new_dim = rimuoviDuplicati(elements, reduced, DIM);

    for(i=0; i<new_dim; i++) {
        printf("%4d", reduced[i]);
    }
    printf("\n");

    return 0;
}

int rimuoviDuplicati(int arr[], int res[], int dim) {
    int i, j, found;
    int count;

    count = 0;
    for(i=0; i<dim; i++) {
        for(j=0, found=0; j<count && !found; j++) {
            if(arr[i] == res[j])
                found = 1;
        }
        if(!found) {
            res[count] = arr[i];
            count++;
        }
    }

    return count;
}
