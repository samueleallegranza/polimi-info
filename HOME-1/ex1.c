#include <stdio.h>
#define MAX 50

int main(void) {
    int prices[MAX];
    int input, qt;
    int exp, max_exp, bought;
    int i;

    scanf("%d", &max_exp);

    qt = 0;
    scanf("%d", &input);
    while(qt<MAX && input>=0) {
        prices[qt] = input;
        qt++;
        scanf("%d", &input);
    }

    exp = 0;
    for(i=0; i<qt && (exp+prices[i] < max_exp); i++) {
        exp += prices[i];
    }

    /* i = number of bought items */
    printf("%d %d\n", i, exp);

    return 0;
}