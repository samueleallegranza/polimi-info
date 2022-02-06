#include <stdio.h>
#include <math.h>
#define BASE 10
#define DIM 10

void trovanarcisisti(int [], int [], int, int);
int narcisista(int, int);

int main(int argc, char * argv[]) {
    int v[DIM] = {153, 370, 1, 2, 3, 9, 371, 407, 11, 12};
    int t[DIM];
    int i;

    trovanarcisisti(v, t, DIM, 3);
    for(i=0; i<DIM; i++) {
        printf("%d - %d\n", v[i], t[i]);
    }

    return 0;
}

int narcisista(int v, int x) {
    int sum, c;

    sum = 0;
    c = v;
    while(c>0 && c<=v) {
        sum += pow((c%BASE), x);
        c /= BASE;
    };

    return (sum==v);
}

void trovanarcisisti(int numero[], int tipo[], int dim, int x) {
    int i;
    for(i=0; i<dim; i++)
        tipo[i] = narcisista(numero[i], x);
}
