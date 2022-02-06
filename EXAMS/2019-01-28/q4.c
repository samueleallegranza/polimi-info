#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PLHOLD 'x'
#define ARG_STR 1
#define START 0

void genera(char [], int);

int main(int argc, char * argv[]) {
    if(argc >= (ARG_STR+1))
        genera(argv[ARG_STR], START);
    else
        printf("Errore.\n");

    return 0;
}

void genera(char input[], int resume){
    int i, len;
    char * s1, * s2;

    //find next 'x'
    for(i=resume; (input[i]!='\0' && input[i] != PLHOLD); i++);

    if(input[i] == '\0')
        printf("%s\n", input);
    else if (input[i] == PLHOLD) {
        len = strlen(input);

        s1 = malloc((sizeof(char) * len) + 1);
        strcpy(s1, input);
        s1[i] = '0';

        s2 = malloc((sizeof(char) * len) + 1);
        strcpy(s2, input);
        s2[i] = '1';

        genera(s1, i+1);
        genera(s2, i+1);
    }
}
