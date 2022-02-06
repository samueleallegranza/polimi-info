#include <stdio.h>
#define SIGN 0
#define PLUS '+'
#define MINUS '-'
#define ZERO '0'

int strel2int(char []);

int main(int argc, char * argv[]) {
    char strn[] = "-1245601";
    printf("%d\n", strel2int(strn));
    return 0;
}

int strel2int(char str[]) {
    int sign, i;
    int num;

    sign = 1;
    i=0;

    if(str[SIGN] == MINUS) {
        sign = -1;
        i = 1;
    } else if(str[SIGN] == PLUS)
        i = 1;

    num = 0;
    for(; str[i] != '\0'; i++){
        printf("%c", str[i]);
        num = (num*10) + (str[i]-ZERO);
    }

    num *= sign;
    return num;
}
