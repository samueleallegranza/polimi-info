#include <stdio.h>
#define START_NUM '0'
#define END_NUM '9'
#define START_LOW 'a'
#define END_LOW 'z'
#define START_UP 'A'
#define END_UP 'Z'
#define ARGV_PWD 1

int is_num(char);
int is_alph(char);
int is_safe(char []);

int main(int argc, char * argv[]) {
    if(argc >= (ARGV_PWD+1)) {
        printf("%d\n", is_safe(argv[ARGV_PWD]));
    } else {
        printf("Error\n");
    }

    return 0;
}

int is_num(char c) {
    return (c>=START_NUM) && (c<=END_NUM);
}

int is_alph(char c){
    return (
        ((c>=START_LOW) && (c<=END_LOW)) ||
        ((c>=START_UP) && (c<=END_UP))
    );
}

int is_safe(char str[]) {
    int p_num, p_symb;
    int i, rep_count;
    char prevc;

    if(str[0] != '\0') {
        prevc = str[0];
        rep_count = 1;
        
        p_num = 0; p_symb = 0;
        if(is_num(str[0]))
            p_num = 1;
        else if(!is_alph(str[0]))
            p_symb = 1;

        i=1;
        while((str[i]!='\0') && (rep_count<3)) {
            if(is_num(str[i]))
                p_num = 1;
            else if(!is_alph(str[i]))
                p_symb = 1;
            if(prevc == str[i])
                rep_count++;
            else {
                rep_count = 1;
                prevc = str[i];
            }
            i++;
        };

        return (p_num) && (p_symb) && (i>=8) && (rep_count<3);
    } else
        return 0; // Invalid password
}
