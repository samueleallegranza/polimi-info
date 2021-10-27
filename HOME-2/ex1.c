#include <stdio.h>
#define OP_BR '('
#define CL_BR ')'

int nesting(char []);

int main(int argc, char * argv[]) {
    printf("%d\n", nesting("(())((())())"));
    return 0;
}

int nesting(char str[]) {
    int i, max, curr;
    max = 0;
    curr = 0;
    for(i=0; str[i] != '\0'; i++) {
        if(str[i] == OP_BR) {
            curr++;
            if(curr > max)
                max = curr;
        }
        else if(str[i] == CL_BR)
            curr--;
    }
    return max;
}
