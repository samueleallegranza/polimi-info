/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    [Consegna mancante]

*/
#include <stdio.h>
#define ROWS
#define COLS
#define FNAME_MAX

void solve(int [][COLS], int [][COLS], int [][COLS], int, int);

int main(int argc, char * argv[]) {

    FILE * fin1, * fin2, * fout;
    char fname_in1[FNAME_MAX];
    char fname_in2[FNAME_MAX];
    char fname_out[FNAME_MAX];

    int m1[ROWS][COLS];
    int m2[ROWS][COLS];
    float mr[ROWS][COLS];

    scanf("%s%s%s", fname_in1, fname_in2, fname_out);

    fin1 = fopen(fname_in1, "rb");
    fin2 = fopen(fname_in2, "rb");
    fout = fopen(fname_out, "wb");

    if(fin1 && fin2 && fout) {
        fread(m1, sizeof(int), ROWS*COLS, fin1);
        fread(m2, sizeof(int), ROWS*COLS, fin2);

        solve(m1, m2, mr, ROWS, COLS);
        fwrite(mr, sizeof(float), ROWS*COLS, fout);

        fclose(fin1); fclose(fin2); fclose(fout);
    } else {
        printf("Errore apertura file\n");
    }

    return 0;
}

void solve(int m1[][COLS], int m2[][COLS], float mr[][COLS], int R, int C) {
    int r,c;
    for(r=0; r<R; r++) {
        for(c=0; c<C; c++) {
            mr[r][c] = (m1[r][c] + m2[r][c]) / 2.0;
        }
    }
}
