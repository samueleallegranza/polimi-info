#include <stdio.h>
#include <ctype.h>
#define ARG_ISBN 1
#define SEP1 1
#define SEP2 5
#define SEP3 11
#define SEPC '-'
#define ISBN_LEN 13
#define ISBN_LEN_RAW 10
#define ZERO '0'

int checkISBN10(char []);

int main(int argc, char * argv[]) {
    if(argc >= (ARG_ISBN+1))
        printf("%d\n", checkISBN10(argv[ARG_ISBN]));
    return 0;
}

int checkISBN10(char isbn[]) {
    int i, valid, sum, dig, dig_mult;

    sum = 0;
    valid = 1;
    dig_mult = ISBN_LEN_RAW;
    for(i=0; i<ISBN_LEN && valid; i++) {
        if(i==SEP1 || i==SEP2 || i==SEP3) {
            if(isbn[i] != SEPC) {
                valid = 0;
            }
        } else {
            if(isdigit(isbn[i])) {
                sum += dig_mult*(isbn[i]-ZERO);
                dig_mult--;
            } else
                valid = 0;
        }
    }

    printf("%d\n", sum);

    return (sum%11==0);
}
