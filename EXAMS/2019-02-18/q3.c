#include <stdio.h>
#define NCOL 10
#define NROW 3

void find_mat_sum(int [][NCOL], int, int, int, int *, int *);

int main(int argc, char * argv[]) {
    int mat[NROW][NCOL] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    
    int r, c;
    find_mat_sum(mat, 29, NROW, NCOL, &r, &c);
    printf("%d - %d\n", r, c);

    return 0;
}

void find_mat_sum(int mat[][NCOL], int val, int r, int c, int *res_c, int *res_r){
    int i, j, sum;

    sum = 0;
    for(i=0; i<r && (sum<=val); i++)
        for(j=0; j<c && (sum<=val); j++)
            sum += mat[i][j];

    if(sum <= val) {
        i = -1;
        j = -1;
    } else {
        i--;
        j--;
    }

    *res_r = i;
    *res_c = j;
}
