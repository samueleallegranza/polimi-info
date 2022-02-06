#include <stdio.h>
#include <stdlib.h>

float * distanzalineare(float, float, int, int);

int main(int argc, char * argv[]) {
    float * res1, * res2;
    int n = 5, i;
    float start = 2.0, stop = 3.0;

    res1 = distanzalineare(start, stop, n, 0);
    res2 = distanzalineare(start, stop, n, 1);

    for(i=0;i<n;i++)
        printf("%.2f\t", res1[i]);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%.2f\t", res2[i]);
    printf("\n");

    return 0;
}

float * distanzalineare(float start, float stop, int n, int exclstop) {
    float * res;
    float offset, step;
    int i;

    if(res = malloc(sizeof(float) * n)) {
        offset = stop-start;
        if(exclstop)
            step = offset/n;
        else
            step = offset/(n-1);

        for(i=0; i<n; i++)
            *(res+i) = start + (step*i);
    }

    return res;
}
