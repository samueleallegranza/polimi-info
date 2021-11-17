#include <stdio.h>
#define DIM 3
#define BLACK 'X'
#define WHITE 'O'

void print_table(int, int);

int main(int argc, char * argv[]) {
    int i,j;
    int comb;

    // calculate max permutations
    comb = 1;
    for(i=0; i<(DIM*DIM); i++) {
        comb *= 2;
    }
    printf("All possible combinations are %d\n", comb);

    for(i=0; i<comb; i++) {
        print_table(i, DIM);
        printf("\n");
    }

    return 0;
}

void print_table(int n, int dim) {
    int i=0, base;
    char c;
    for (i=0; i<(dim*dim); i++) {
        if(i%dim == 0) {
            printf("\n");
        }
        if(n%2)
            c = BLACK;
        else
            c = WHITE;
        printf("%c", c);
        n /= 2;
    }
}