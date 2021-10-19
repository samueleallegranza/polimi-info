/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Testo mancante 

*/

#include <stdio.h>

int main(int argc, char * argv[]) {

    int a, b, res;
    int exp, pow, j;

    do{
        scanf("%d", &a);
    }while(a<=0);
    do{
        scanf("%d", &b);
    }while(b<=0);

    if(!(a == 1 && b != 1)) {
        exp = 0;
        pow = 1;
        while(pow<b) {
            exp++;
            pow *= a;
        }

        if(pow == b) {
            res = exp;
        } else {
            res = -1;
        }
    } else {
        res = -1;
    }

    printf("%d\n", res);

    return 0;
}
