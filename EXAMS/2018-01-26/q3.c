#include <stdio.h>
#include <stdlib.h>
#define DIM 5

int seq_matrix(int [][DIM], int);

int main(int argc, char * argv[]) {

    int matrix[DIM][DIM] = {
        {1,2,3,4,5},
        {2,3,4,5,1},
        {3,4,5,1,2},
        {4,5,1,2,3},
        {5,1,2,3,4}
    };

    printf("%d\n", seq_matrix(matrix, DIM));

    return 0;
}

int seq_matrix(int m[][DIM], int dim) {
    int row_ok, col_ok;
    int i, j;
    int * counters;

    counters = malloc(sizeof(int) * dim);
    row_ok = 1;
    col_ok = 1;
    for(i=0; i<dim && row_ok; i++) {
        //reset counters
        for(j=0; j<dim; j++)
            counters[j] = 0;
        // check row
        for(j=0; j<dim && row_ok; j++)
            if(m[i][j] >= 1 && m[i][j] <= 5)
                counters[m[i][j]-1] = 1;
            else
                row_ok = 0;
        // determine if row is valid
        for(j=0; j<dim && row_ok; j++)
            row_ok = (counters[j] == 1);
    }

    if(row_ok) {
        for(i=0; i<dim && col_ok; i++) {
            //reset counters
            for(j=0; j<dim; j++)
                counters[j] = 0;
            // check row
            for(j=0; j<dim && col_ok; j++)
                if(m[j][i] >= 1 && m[j][i] <= 5)
                    counters[m[j][i]-1] = 1;
                else
                    row_ok = 0;
            // determine if row is valid
            for(j=0; j<dim && col_ok; j++)
                row_ok = (counters[i] == 1);
        }
    }

    return (col_ok == 1) && (row_ok == 1);
}
