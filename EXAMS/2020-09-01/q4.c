#include <stdio.h>
#include <ctype.h>
#define QT_ALPH 'z' - 'a'
#define START_LOW 'a'
#define START_UP 'A'
#define END_LOW 'z'
#define END_UP 'Z'

int pangramma(char []);
int alph_idx(char);

int main(int argc, char * argv[]) {
    char str1[] = "The quick brown fox jumps over the lazy dog";
    char str2[] = "This is not a Pangram!";

    printf("%s\n\tPangram: %d\n\n", str1, pangramma(str1));
    printf("%s\n\tPangram: %d\n\n", str2, pangramma(str2));

    return 0;
}

int pangramma(char str[]) {
    int i, pan, idx;
    char bitmap[QT_ALPH];

    for(i=0; i<QT_ALPH; i++)
        bitmap[i] = 0;

    for(i=0; str[i]!='\0'; i++) {
        idx = alph_idx(str[i]);
        if(idx != -1)
            bitmap[idx] = 1;
    }

    pan = bitmap[0];
    i = 1;
    while(pan && i<QT_ALPH) {
        pan = bitmap[i];
        i++;
    }

    return pan;
}

int alph_idx(char c) {
    if((c>=START_LOW && c<=END_LOW) || (c>=START_UP && c<=END_UP)) {
        c = tolower(c);
        return c-START_LOW;
    } else
        return -1;
}
