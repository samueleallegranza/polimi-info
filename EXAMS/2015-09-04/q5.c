#include <stdio.h>
#define DIM 13

int maxel_subsq(int [], int, int *);

int main(int argc, char * argv[]){
    int len, res;
    int vals[DIM] = {3,4,4,5,5,5,6,7,8,8,8,9,0};
    res = maxel_subsq(vals, DIM, &len);
    printf("elm: %d\tlen: %d\n", res, len);
    return 0;
}

// Returns the element's value. To obtain the length you have to pass
// a pointer to store this result (res_dim).
int maxel_subsq(int arr[], int dim, int * res_dim){
    int i, eq, maxeq, maxel;

    eq = 1;
    maxeq = eq;
    maxel = arr[0];
    for(i=1; i<dim; i++){
        if(arr[i] == arr[i-1])
            eq++;
        else
            eq = 1;
        if(eq>maxeq) {
            maxeq = eq;
            maxel = arr[i];
        }
    }

    *res_dim = maxeq;
    return maxel;
}
