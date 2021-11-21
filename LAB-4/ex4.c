#include <stdio.h>
#include <stdlib.h>

#define START 2.0
#define STOP 3.0
#define COUNT 5
#define STOPEXCL 1

float * distanzalineare(float, float, int, int);

int main(int argc, char * argv[]) {
    float * res;
    int i;

    res = distanzalineare(START, STOP, COUNT, STOPEXCL);
    for(i=0; i<5; i++) {
        printf("%.2f\t", res[i]);
    }
    printf("\n");

    return 0;
}

float * distanzalineare(float start, float stop, int count, int stopexcl) {
    float dist, off;
    float * res;
    int i;

    res = malloc(sizeof(float) * count);
    dist = stop-start;
    off = dist/(count-1+stopexcl);

    for(i=0; i<count; i++) {
        res[i] = (off*i)+start;
    }

    return res;
}
