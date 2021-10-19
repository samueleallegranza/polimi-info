#include <stdio.h>
#define DIM 50
#define MULTIPLIER 9

int main(void) {
    char str[DIM+1];
    char comp[(DIM*2)+1];
    int multiplier, i, j;
    char stacking;

    scanf("%s", str);

    stacking=str[0];
    multiplier=1;
    for(i=1; str[i]!='\0'; i++) {
        if((multiplier == MULTIPLIER) || (str[i] != stacking)) {
            printf("%c%d", stacking, multiplier);
            stacking = str[i];
            multiplier = 1;
        } else {
            multiplier++;
        }
    }
    printf("%c%d\n", stacking, multiplier);

    return 0;
}
