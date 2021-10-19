#include <stdio.h>
#define DIM 4

int main(void) {
    int matrix[DIM][DIM];
    int transp[DIM][DIM];
    int i,j;

    for(i=0; i<DIM; i++)
        for(j=0; j<DIM; j++)
            scanf("%d", &matrix[i][j]);

    for(j=0; j<DIM; j++) 
        for(i=0; i<DIM; i++)
            transp[i][j] = matrix[j][i];

    for(i=0; i<DIM; i++) {
        for(j=0; j<DIM; j++)
            printf("%5d", transp[i][j]);
        printf("\n");
    }

    return 0;
}