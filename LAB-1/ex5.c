#include <stdio.h>

int main(int argc, char * argv[]) {
    int num,i;
    int tronc;
    int prime,p,n;

    do {
        scanf("%d", &num);
    } while (num<=0);

    tronc = 1;
    while(tronc==1 && num>0) {

        p=2;
        n=num;
        while(p<=n && n%p!=0) {
            p++;
        }
        if(num==1 || p<(n-1)){
            // not prime number
            tronc = 0;
        }

        num /= 10;
    }

    printf("%d\n", tronc);

    return 0;
}