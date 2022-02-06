#include <stdio.h>
#include <math.h>
#include "../../lib/listi.c"
#define DIM 5

listi_t * cmp_listidx(int [], int, int);

int main(int argc, char * argv[]) {
    int v[DIM] = {1000, 2, 100, 6, 105};
    int soglia = 5;
    listi_t * h;

    h = cmp_listidx(v, soglia, DIM);
    print_list(h);

    return 0;
}

listi_t * cmp_listidx(int seq[], int soglia, int dim){
    listi_t * h = NULL;
    int i, sq_soglia;

    sq_soglia = pow(soglia, 2);
    for(i=0; i<dim; i++)
        if(seq[i] > sq_soglia)
            h = append(h, i);

    return h;
}
