#include <stdio.h>
#define DIM 50
#define MULTIPLIER 9

int main(void) {
    char str[DIM+1];
    char ch; int mult;
    int i,j;

    scanf("%s", str);

    for(i=0; str[i]!='\0'; i+=2) {
        ch = str[i];
        mult = str[i+1] - '0';
        for(j=0; j<mult; j++) {
            printf("%c", ch);
        }
    }
    printf("\n");

    return 0;
}
