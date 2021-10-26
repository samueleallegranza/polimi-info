#include <stdio.h>
#define DIM 50
#define DIM_NOTCOMP (DIM/2 * 9)
#define MULTIPLIER 9

int main(void) {
    char comp[DIM+1];
    char str[DIM_NOTCOMP+1];
    char ch; int mult;
    int i, j, s;

    scanf("%s", comp);

    for(i=0, s=0; comp[i]!='\0'; i+=2) {
        ch = comp[i];
        mult = comp[i+1] - '0';
        for(j=0; j<mult; j++) {
            str[s] = ch;
            s++;
        }
    }
    str[s] = '\0';

    printf("%s\n", str);

    return 0;
}
