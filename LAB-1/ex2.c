#include <stdio.h>

int main(int argc, char * argv[]) {
    int a,b, res;
    scanf("%d %d", &a, &b);
    
    //res = !(a%b==0 || b%a==0)
    if(a%b==0 || b%a==0)
        res = 1;
    else
        res = 0;

    printf("%d\n", res);

    return 0;
}