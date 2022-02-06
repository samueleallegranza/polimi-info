#include <stdio.h>
#include <stdlib.h>
#define BYTE_BITS 8
#define BASE 2
#define NUM_OFFSET '0'
#define INPUT_MAX 20

char * char2ascii(char);

int main(int argc, char * argv[]) {
    char * res;
    char input[INPUT_MAX+1];
    int i;

    scanf("%s", input);
    for(i=0; input[i]!='\0'; i++) {
        res = char2ascii(input[i]);
        printf("%s", res);
    }

    printf("\n");

    return 0;
}

char * char2ascii(char c) {
    int v, i;
    char * res;

    if(res = malloc(sizeof(char) * (BYTE_BITS+1))) {
        v = c;
        for(i=0; i<BYTE_BITS; i++) {
            *(res+(BYTE_BITS-i-1)) = ((v%BASE) + NUM_OFFSET);
            v /= BASE;
        }
        *(res+i) = '\0';
    }

    return res;
}
