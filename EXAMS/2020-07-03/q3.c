#include <stdio.h>
#include <stdlib.h>
#define BASE 10

int cifra(int);
int cmp_counters(int *);
int cmp_counters2(int *);

int main(int argc, char * argv[]) {
    int n = 37731;
    printf("%d -> %d\n", n, cifra(n));
    return 0;
}

int cifra(int n) {
    int * counters;
    int curr, i;

    counters = malloc(sizeof(int) * BASE);
    for(i=0; i<BASE; i++)
        counters[i] = 0;

    while(n>0) {
        curr = n%BASE;
        counters[curr]++;
        n /= 10;
    }

    return cmp_counters(counters);
}

int cmp_counters(int counters[]) {
    int i, maxi;

    maxi=0;
    for(i=1; i<BASE; i++) {
        if(counters[i] > counters[maxi])
            maxi = i;
        else if((counters[i] == counters[maxi]) && (i>maxi)) {
            maxi = i;
        }
    }

    return maxi;
}

int cmp_counters2(int counters[]) {
    int stuck, minp, maxd;
    int i, maxi;

    stuck = 0;
    maxi = 0;
    for(i=1; i<BASE && !stuck; i++) {
        if(counters[i] > counters[maxi])
            maxi = i;
        else if(counters[i] == counters[maxi])
            stuck = 1;
    }


    if(stuck) {
        minp = -1;
        maxd = -1;
        for(i=0; i<BASE; i++) {
            if((counters[i]>0) && (i%2==0))
                if(minp==-1 || i<minp)
                    minp = i;
            if((counters[i]>0) && (i%2==1))
                if(maxd=-1 || i>maxd)
                    maxd = i;
        }
    }

    if(stuck)
        if(minp != -1)
            return minp;
        else
            return maxd;
    else
        return maxi;

}
