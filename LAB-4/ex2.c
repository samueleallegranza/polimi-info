#include <stdio.h>
#include <string.h>
#define MAXLEN 500

int main(int argc, char * argv[]) {
    char input[MAXLEN+1];
    int i, len, count;

    scanf("%s", input);
    len = strlen(input);

    count = 1;
    for(i=(len-2); i>=0; i--) {
        if(input[i] != input[i+1]) {
            printf("%c%d", input[i+1], count);
            count=0;
        }
        count++;
    }
    printf("%c%d\n", input[i+1], count);

    return 0;
}
