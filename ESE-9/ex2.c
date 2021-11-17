/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un programma che chiede all'utente di inserire il
    nome di un file di test (max 60 caratteri) conetenente i dati
    dell'esercizio precedente.
    La dimensione massima per la matrice e' 10x10, il file contiene
    nella prima riga il numero di righe e colonne della matrice,
    seguono poi le righe della matrice. Infine sull'ultima riga e'
    contenuta la posizione di partenza.

    Il file se esiste contiene dei dati senz'altro compatibile con
    la dimensione massima della matrice.
*/
#include <stdio.h>
#define FILENAME_MAX 60
#define ROWS 10
#define COLS 10
#define OFFSET 9

int connected(int [][COLS], int, int, int, int, int);
int print_matrix(int [][COLS], int, int);

int main(int argc, char * argv[]) {
    FILE * fin;
    char filename[FILENAME_MAX];

    int r,c;
    int rows, cols;
    int init_r, init_c;
    int matrix[ROWS][COLS];
    int result;

    scanf("%s", filename);

    if(fin=fopen(filename, "r")) {
        fscanf(fin, "%d%d", &rows, &cols);
        for(r=0; r<rows; r++) {
            for(c=0; c<cols; c++) {
                fscanf(fin, "%d", &matrix[r][c]);
            }
        }
        fscanf(fin, "%d%d", init_r, init_c);
        fclose(fin);

        result = connected(matrix, rows, cols, init_r, init_c, 1);
        printf("%d", result);
    } else {
        printf("Errore apertura file!");
    }

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