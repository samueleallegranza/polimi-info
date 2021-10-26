#include <stdio.h>
#define FIRST_LOWER 'a'
#define LAST_LOWER 'z'
#define FIRST_UPPER 'A'
#define LAST_UPPER 'Z'
#define NUM_LETTERS 26

void caesar(char [], int);

int main(int argc, char * argv[]) {
    char text[] = "ZANZARA";
    caesar(text, 1);
    printf("%s\n", text);
    return 0;
}

void caesar(char str[], int key) {
    int i, starter;

    if(str[0] >= FIRST_LOWER && str[0] <= LAST_LOWER)
        starter = FIRST_LOWER;
    else if(str[0] >= FIRST_UPPER && str[0] <= LAST_UPPER)
        starter = FIRST_UPPER;

    for(i=0; str[i]!='\0'; i++) {
        str[i] = starter + (((str[i] - starter) + key) % NUM_LETTERS);
    }
}
