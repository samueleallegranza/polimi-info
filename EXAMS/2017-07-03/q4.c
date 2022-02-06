#include <stdio.h>
#include <string.h>
#define MAXLEN 500

int main(int argc, char * argv[]) {
    int i, len, count;
    char str[MAXLEN + 1], c;

    scanf("%s", str);
    len = strlen(str);

    c = str[len-1]; count = 1;
    for(i=(len-2); i>=0; i--) {
        if(c == str[i])
            count++;
        else {
            printf("%c%d", c, count);
            count = 1;
            c = str[i];
        }
    }
    printf("%c%d\n", c, count);

    return 0;
}
