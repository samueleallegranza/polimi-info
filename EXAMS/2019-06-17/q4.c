#include <stdio.h>
#include <math.h>
#define FN_MAX 30
#define FN_OUT "primi.txt"

int primecount(int);
int isprime(int);

int main(int argc, char * argv[]) {
    char fn_in[FN_MAX+1];
    FILE * fin, * fout;
    int v;

    scanf("%s", fn_in);
    if(fin = fopen(fn_in, "r")) {
        if(fout = fopen(FN_OUT, "w")) {
            while(fscanf(fin, "%d", &v) == 1)
                fprintf(fout, "%d %d\n", v, primecount(v));
            fclose(fin);
            fclose(fout);
        } else {
            fclose(fin);
            printf("Errore apertura file output.\n");
        }
    } else {
        printf("Errore apertura file input.\n");
    }

    return 0;
}

int primecount(int n) {
    int count, i;
    count = 0;
    for(i=2; i<=n; i++){
        count += isprime(i);
        printf("%d is prime? %d\n", i, isprime(i));
    }
    return count;
}

int isprime(int n) {
    int sqrt_n, i, prime;
    if(n<2) {
        return 0;
    } else if(n == 2) {
        return 1;
    } else if(n%2 == 0) {
        return 0;
    } else {
        prime = 1;
        sqrt_n = sqrt(n);
        for(i=3; (i<=sqrt_n) && prime; i+=2) {
            if(n%i == 0)
                prime = 0;
        }
        return prime;
    }
}
