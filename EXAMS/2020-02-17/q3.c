#include <stdio.h>
#define RADIUS 3
#define AREA (RADIUS*RADIUS)
#define NR 5
#define NC 6

void filter_img(float [][NC], float [][NC], int, int);
float floating_avg(float [][NC], int, int, int, int);

int main(int argc, char * argv[]) {
    int i, j;
    float image[NR][NC] = {
        {0.7, 1.5, 5.4, 7.7, 2.2, 1.1},
        {-0.5, 1.0, 4.0, 7.0, 8.3, 2.4},
        {-0.6, 4.0, 5.0, 2.8, -8.7, 1.2},
        {2.0, 7.0, -1.8, -2.0, 5.4, 0.0},
        {9.0, 5.6, 9.9, -5.4, 5.6, 3.2}
    };
    float filtered[NR][NC];
    filter_img(image, filtered, NR, NC);

    for(i=0; i<NR; i++) {
        for(j=0; j<NC; j++)
            printf("%f ", filtered[i][j]);
        printf("\n");
    }

    return 0;
}

void filter_img(float image[][NC], float filtered[][NC], int r, int c) {
    int i,j;

    for(i=0; i<r; i++) {
        for(j=0; j<c; j++)
            filtered[i][j] = floating_avg(image, r, c, i, j);
    }
}

float floating_avg(float img[][NC], int r, int c, int x, int y){
    int i, j;
    float avg, sum;

    sum = 0;
    for(i=(x-1); i<=(x+1); i++) {
        for(j=(y-1); j<=(y+1); j++) {
            if(i>=0 && j>=0 && i<r && j<c)
                //printf("[%d][%d](%.1f)\t", i, j, img[i][j]);
                sum += img[i][j];
        }
    }

    avg = sum/AREA;
    return avg;
}
