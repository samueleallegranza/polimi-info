#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 200

int is_prime(int);
int compattarray(int [], int);

int main(int argc, char * argv[]) {
    int * vals, dim, i, new_dim;

    do{
        scanf("%d", &dim);
    } while(dim<1 && dim>MAX);

    vals = malloc(sizeof(int) * dim);

    for(i=0; i<dim; i++)
        scanf("%d", (vals+i));

    new_dim = compattarray(vals, dim);

    for(i=0; i<new_dim; i++)
        printf("%d\t", *(vals+i));
    printf("\n");

    return 0;
}

int is_prime(int n) {
    int i, prime, sqrt_n;

    if(n<2 || n%2==0)
        prime = 0;
    else if(n == 2)
        prime = 1;
    else {
        sqrt_n = sqrt(n);
        prime = 1;
        for(i=3; i<=sqrt(n) && prime; i+=2);
            prime = (n%i!=0);
    }
    return prime;
}

int compattarray(int arr[], int dim) {
    int i, j, new_dim;

    new_dim = dim;
    for(i=0; i<new_dim; i++)
        if(!is_prime(arr[i])) {
            for(j=i+1; j<new_dim; j++)
                arr[j-1] = arr[j];
            new_dim--;
            i--;
        }

    return new_dim;
}
