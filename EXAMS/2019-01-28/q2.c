#include <stdio.h>

void sort_substr(char [], int, int);

int main(int argc, char * argv[]) {
    char str1[] = "ringraziamento";
    char str2[] = "indistruttibile";
    char str3[] = "ba";
    sort_substr(str1, 2, 6);
    sort_substr(str2, 8, 10);
    sort_substr(str3, 0, 1);
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);
}

void sort_substr(char str[], int n, int m) {
    int i, maxi, tmp, j;

    for(i=n; i<=(m-1); i++) {
        maxi = i;
        for(j=(i+1); j<=m; j++)
            if(str[j] > str[maxi])
                maxi = j;
        tmp = str[i];
        str[i] = str[maxi];
        str[maxi] = tmp;
    }
}
