#include <stdio.h>
#define DIM 50
#define DIM_COMP (DIM*2)
#define MULTIPLIER 9

int main(void) {
    char str[DIM+1];
    char comp[DIM_COMP+1];
    int multiplier, i, j;
    char stacking;

    scanf("%s", str);

    stacking=str[0];
    multiplier=1;
    for(i=1, j=0; str[i]!='\0'; i++) {
        if((multiplier == MULTIPLIER) || (str[i] != stacking)) {
            comp[j] = stacking;
            comp[j+1] = '0' + multiplier;
            j+=2;
            stacking = str[i];
            multiplier = 1;
        } else {
            multiplier++;
        }
    }
    comp[j] = stacking;
    comp[j+1] = multiplier;
    comp[j+2] = '\0';

    printf("%s\n", comp);

    return 0;
}
