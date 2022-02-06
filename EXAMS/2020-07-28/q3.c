#include <stdio.h>
#include <math.h>
#define DIM 6
#define RES_DIM 3

void meanvarstd(int [], int , float []);

int main(int argc, char * argv[]) {
    int vals[DIM] = {1, 4, 5, -2, 0, 3};
    float res[RES_DIM];

    meanvarstd(vals, DIM, res);
    printf("avg: %.2f\nvar: %.2f\nstdv: %.2f\n", res[0], res[1], res[2]);

    return 0;
}

void meanvarstd(int vals[], int dim, float res[]) {
    float avg, var, stdev;
    int c, sum;

    sum = 0;
    for(c=0; c<dim; c++)
        sum += vals[c];

    avg = (float) sum/dim;
    var = 0;
    for(c=0; c<dim; c++)
        var += pow((vals[c] - avg), 2);

    var /= dim;
    stdev = sqrt(var);

    res[0] = avg;   res[1] = var;   res[2] = stdev;
}
