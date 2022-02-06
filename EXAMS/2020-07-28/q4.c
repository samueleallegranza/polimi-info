#include <stdio.h>
#include <stdlib.h>
#define NR 3
#define NC 4

float * centra(int [][NC], int , int);

int main(int argc, char * argv[]) {
    int v[NR][NC] = {
        {1, 2, 3, 4},
        {2, 6, 3, 40},
        {3, 7, 1, 4}
    };
    float * res;
    int i,j;

    res = centra(v, NR, NC);
    for(i=0; i<NR; i++){
        for(j=0; j<NC; j++)
            printf("%.2f\t", *(res+(i)+(j*i)));
        printf("\n");
    }

    return 0;
}

float * centra(int v[][NC], int r, int c){
    float * res, * avgs;
    int i, j;
    int sumc;

    res = malloc(sizeof(float) * (r*c));
    avgs = malloc(sizeof(float) * c);

    for(j=0; j<c; j++){
        sumc = 0;
        for(i=0; i<r; i++)
            sumc += v[i][j];
        avgs[j] = (float) sumc / r;
    }

    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) {
            *(res+i+(i*j)) = v[i][j] - avgs[j];
        }
    }

    free(avgs);
    return res;
}
