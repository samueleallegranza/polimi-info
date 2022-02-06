#include <stdio.h>
#define START_LOW 'a'
#define START_UP 'A'
#define END_LOW 'z'
#define END_UP 'Z'
#define START_NUM '0'
#define END_NUM '9'
#define SPACE ' '

int is_punctuation(char);
int rm_punctuation(char []);

int main(int argc, char * argv[]) {
    char str[] = "This` is. Just some, text t0 try!";
    int rms = 0;
    rms = rm_punctuation(str);
    printf("%d\n%s\n", rms, str);
    return 0;
}

int is_punctuation(char c){
    return !(
        (c>=START_UP && c<=END_UP) ||
        (c>=START_LOW && c<=END_LOW) ||
        (c>=START_NUM && c<=END_NUM) ||
        (c==SPACE)
    );
}

int rm_punctuation(char str[]) {
    int i, ni;
    int count;

    ni = 0;
    count = 0;
    for(i=0; str[i]!='\0'; i++) {
        if(!is_punctuation(str[i])) {
            str[ni] = str[i];
            ni++;
        } else
            count++;
    }
    str[ni] = '\0';

    return count;
}
