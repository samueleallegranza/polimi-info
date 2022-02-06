#include <stdio.h>
#define SPACE ' '

char * find_longest(char []);

int main(int argc, char * argv[]) {
    char str[] = "How cool this algorithm works!";
    char * l;
    int i;

    l = find_longest(str);
    for(i=0; *(l+i)!='\0' && *(l+i)!=SPACE; i++)
        printf("%c", *(l+i));
    printf("[>]\n[>] = sanity check.\n");

    return 0;
}

char * find_longest(char str[]) {
    int len, i, max;
    char * start, * max_start;

    len = 0;
    max = -1;
    start = &str[0];
    max_start = start;

    for(i=0; str[i]!='\0'; i++) {
        if(str[i] == SPACE) {
            if(len>max){
                max = len;
                max_start = start;
            }
            start = &str[i+1];
            len = 0;
        } else
            len++;
    }
    if(len>max)
        max_start = start;

    return max_start;
}
