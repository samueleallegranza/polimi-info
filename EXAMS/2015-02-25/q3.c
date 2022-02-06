#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * strcopy(char *);

int main(int argc, char * argv[]) {
    char str[] = "Hello world!";
    char * copy;
    copy = strcopy(str);
    printf("%s\n", copy);
    return 0;
}

char * strcopy(char str[]) {
    char * new;
    int i;

    new = malloc(sizeof(char) * (strlen(str) + 1));
    for(i=0; str[i]!='\0'; i++)
        *(new+i) = str[i];
    *(new+i) = '\0';        // To be sure that '\0' is in place

    return new;
}
