#include <stdio.h>
#define NR 4
#define NC 8

int domCount(int [][NC], int, int);

int main(int argc, char * argv[]) {
    int info[NR][NC] = {
        {5,9,2,4,1,7,2,4},
        {3,5,6,2,5,6,1,2},
        {1,3,4,7,8,8,3,0},
        {1,3,5,6,7,8,2,1}
    };

    printf("%d\n", domCount(info, NR, NC));

    return 0;
}

int domCount(int num[][NC], int nr, int nc) {
    int count;
    int i, j, x, y;
    int dom;

    count = 0;
    for(i=0; i<nr-1; i++) {
        for(j=0; j<nc-1; j++) {
            dom = 1;
            x = i+1;
            while(dom && x<nr) {
                y = j+1;
                while(dom && y<nc) {
                    if(num[x][y] >= num[i][j]) {
                        dom = 0;
                    }
                    y++;
                }
                x++;
            }
            count += dom;
        }
    }

    return count;
}
