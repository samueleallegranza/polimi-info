#include <stdio.h>
#define DIM 4

int main(void) {
    int matrix[DIM][DIM];
    int i,j, tmp;

    for(i=0; i<DIM; i++)
        for(j=0; j<DIM; j++)
            scanf("%d", &matrix[i][j]);

    for(i=0; i<DIM-1; i++) {
      for(j=i+1; j<DIM; j++) {
        tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
      }
    }

    for(i=0; i<DIM; i++) {
        for(j=0; j<DIM; j++)
            printf("%5d", matrix[i][j]);
        printf("\n");
    }

    return 0;
}
