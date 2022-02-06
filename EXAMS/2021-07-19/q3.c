#include <stdio.h>
#define NC 10
#define NR 6
#define CRAT_LVL 2
#define SURR_LVL 1

void erupt(int [][NC], int, int, int, int);
void visualizzamappa(int [][NC], int, int);

int main(int argc, char * argv[]) {
    int area[NR][NC] = {
        {3, 0, 6, 1, 5, 1, 5, 6, 8, 1},
        {0, 0, 5, 6, 0, 5, 4, 0, 5, 6},
        {1, 0, 8, 1, 2, 6, 4, 6, 5, 6},
        {5, 1, 8, 6, 0, 0, 0, 0, 0, 0},
        {5, 1, 5, 1, 3, 1, 1, 0, 7, 1},
        {3, 1, 8, 1, 0, 0, 0, 0, 0, 0}
    };

    visualizzamappa(area, NR, NC);
    printf("\n");
    erupt(area, NR, NC, 1, 3);
    visualizzamappa(area, NR, NC);

    return 0;
}

void erupt(int area[][NC], int nr, int nc, int x, int y) {
    int prev_state;
    int i, j;

    prev_state = area[x][y];
    area[x][y] += CRAT_LVL;

    for(i=x-1; i<=(x+1); i++) {
        for(j=y-1; j<=(y+1); j++) {
            if(i>=0 && j>=0 && i<nr && j<nc && !(i==x && j==y)) {
                if(area[i][j]<prev_state)
                    area[i][j] += SURR_LVL;
            }
        }
    }
}


void visualizzamappa(int area[][NC], int nr, int nc) {
    int i, j;

    for(i=0; i<nr; i++) {
        for(j=0; j<nc; j++)
            printf("%d ", area[i][j]);
        printf("\n");
    }
}
