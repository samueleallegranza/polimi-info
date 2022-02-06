#include <stdio.h>
#define DIM 10

int vcmp_rot(int[], int[], int, int);

int main(int argc, char * argv[]) {
    int i, eq, dx_rot;
    int v1[DIM], v2[DIM];

    for(i=0; i<DIM; i++)
        scanf("%d", &v1[i]);
    for(i=0; i<DIM; i++)
        scanf("%d", &v2[i]);

    i=0;
    eq = -1;
    while((eq==-1) && (i<DIM)) {
        eq = vcmp_rot(v1, v2, DIM, i);
        i++;
    }

    if(eq != -1){
        i--;
        printf("%d", (DIM-i)%DIM);
    } else
        printf("%d", eq);

    return 0;
}

int vcmp_rot(int v1[], int v2[], int dim, int start) {
    int eq, i;

    i=0;
    while((v1[i] == v2[(start+i)%dim]) && (i<dim))
        i++;

    if(i==dim)
        return 1;
    else
        return -1;
}
