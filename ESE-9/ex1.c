/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma che ricevuta in ingresso una
    matrice di interi (e qualsiasi altro parametro ritenuto
    strettamente necessario) e le coordinate di un punto
    iniziale.
    Una cella in posizione (i,j) e' connessa al punto iniziale
    se partendo da questo e' possibile raggiungere (i,j),
    spostandosi in orizzontale o verticale, attraverso solamente
    celle con lo stesso valore del punto iniziale.
    Per risolvere l'esercizio e' ammesso modificare la matrice
    passata in ingresso.
*/

#include <stdio.h>
#define ROWS 3
#define COLS 4
#define OFFSET 9

int connected(int [][COLS], int, int, int, int, int);
int print_matrix(int [][COLS], int, int);

int main(int argc, char * argv[]) {
    // Test inputs
    int matrix[ROWS][COLS] = {
        {0,0,1,0},
        {1,0,1,0},
        {0,0,0,2},
    };
    int init_r = 0;
    int init_c = 0;

    // Varibles for output
    int result;
    int ref_val = matrix[init_r][init_c];

    result = connected(matrix, ROWS, COLS, init_r, init_c, 1);
    printf("Connected columns (reference value is %d): %d\n", ref_val, result);

    return 0;
}

int print_matrix(int m[][COLS], int r, int c) {
    int i,j;
    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) {
            printf("%2d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int connected(int m[][COLS], int R, int C, int c_r, int c_c, int debug) {
    int value = m[c_r][c_c];
    int reachable = 1; // Itself

    if(debug) 
        print_matrix(m, R, C);

    m[c_r][c_c] = value + OFFSET;

    // UP
    if(c_c>0){
        if(m[c_r][c_c-1] == value) {
            reachable += connected(m, R, C, c_r, c_c-1, debug);
        }
    }

    // DOWN
    if((c_c+1)<C){
        if(m[c_r][c_c+1] == value) {
            reachable += connected(m, R, C, c_r, c_c+1, debug);
        }
    }

    // RIGHT
    if((c_r+1)<R){
        if(m[c_r+1][c_c] == value) {
            reachable += connected(m, R, C, c_r+1, c_c, debug);
        }
    }

    // LEFT
    if(c_r>0){
        if(m[c_r-1][c_c] == value) {
            reachable += connected(m, R, C, c_r-1, c_c, debug);
        }
    }

    return reachable;
}