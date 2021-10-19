#include <stdio.h>
#define PAD '0'

int main(int argc, char * argv[]) {

    int num, k;
    int dig, zeroes, tmp;
    int i;

    do {
        scanf("%d", &num);
    } while (num<=0);
    do {
        scanf("%d", &k);
    } while (k<=0);

    // Conta cifre
    dig = 0;
    tmp = num;
    while(tmp>0) {
        dig++;
        tmp /= 10;
    }

    zeroes = k-dig;
    // Aggiungi zeri
    for(i=0; i<zeroes; i++){
        printf("%c", PAD);
    }
    
    printf("%d\n", num);

    return 0;
}