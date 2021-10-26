#include <stdio.h>
#define MAX 50

int main(void) {
    float prices[MAX];
    float input;
    float exp, max_exp;
    int i, qt, bought;

    qt = 0;
    scanf("%f", &input);
    while(qt<MAX && input>=0) {
        prices[qt] = input;
        qt++;
        scanf("%f", &input);
    }

    do {
      scanf("%f", &max_exp);
    } while(max_exp < 0);

    exp = 0;
    bought = 0;
    for(i=0; i<qt; i++) {
        if(exp + prices[i] <= exp) {
          exp += prices[i];
          bought++;
        }
    }

    // Se i prezzi sono strettamente positivi
    // for(i=0; i<qt && (exp+prices[i] < max_exp); i++) {
    //    exp += prices[i];
    // }

    /* i = number of bought items */
    printf("%d %f\n", bought, exp);

    return 0;
}
