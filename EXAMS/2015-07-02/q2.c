#include <stdio.h>

int main(int argc, char * argv[]) {
    int prev, curr, is_miss, miss;

    is_miss = 0;
    scanf("%d%d", &prev, &curr);
    while(curr!=0){
        if(curr != prev+1) {
            miss = prev+1;
            is_miss = 1;
        }
        prev = curr;
        scanf("%d", &curr);
    }

    if(is_miss)
        printf("Missing: %d\n", miss);
    else
        printf("No missing value\n");

    return 0;
}
