#include <stdio.h>
#define BASE 10

int maxdec(int);

int main(int argc, char * argv[]) {
    printf("%d\n", maxdec(1232012700));
    return 0;
}

int maxdec(int n) {
    int curr, max_rem;
    if(n/BASE == 0)
        return n;
    else {
        curr = n%BASE;
        max_rem = maxdec(n/BASE);
        if(curr > max_rem)
            return curr;
        else
            return max_rem;
    }
}
