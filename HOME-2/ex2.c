#include <stdio.h>
#define OP_BR '('
#define CL_BR ')'

int is_balanced(char []);

int main(int argc, char * argv[]) {
    printf("%d\n", is_balanced("((())(())())()"));
    printf("%d\n", is_balanced("((())(())()"));
    printf("%d\n", is_balanced(")))"));
    return 0;
}

int is_balanced(char str[]) {
    int i, sum, balanced;

    sum = 0;
    balanced = 1;
    for(i=0; str[i]!='\0' && balanced; i++) {
        if(str[i] == OP_BR) {
            sum++;
        } else if(str[i] == CL_BR) {
            sum--;
        }
        balanced = sum>=0;
    }
    balanced = (sum==0);

    return balanced;
}
