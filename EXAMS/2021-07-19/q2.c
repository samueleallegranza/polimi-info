#include <stdio.h>
#include <stdlib.h>

float * cercabassi(float [], int, int *);
void analizzabassi(float [], int);

int main(int argc, char * argv[]) {
    int qt, i, resqt;
    float * res, * v;

    do {
        scanf("%d", &qt);
    } while(qt<1);

    if(v = malloc(sizeof(float) * qt)) {
        for(i=0; i<qt; i++)
            scanf("%f", (v+i));
        analizzabassi(v, qt);
        res = cercabassi(v, qt, &resqt);
        analizzabassi(res, resqt);
    }

    return 0;
}

float * cercabassi(float v[], int dim, int * rescount) {
    float * res;
    int i, upper_bound, count;

    if(res = malloc(sizeof(float) * (dim-2))) {
        upper_bound = dim-1;
        count = 0;
        for(i=1; i<upper_bound; i++)
            if(v[i]<v[i-1] && v[i]<v[i+1]) {
                *(res+count) = v[i];
                count++;
            }
    } else {
        count = -1;
    }

    *rescount = count;
    return res;
}

void analizzabassi(float v[], int d) {
    int i;
    for(i=0; i<d; i++)
        printf("%.2f\t", v[i]);
    printf("\n");
}
