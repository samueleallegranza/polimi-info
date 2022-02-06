#include <stdio.h>

int diff(FILE *, FILE *);

int main(int argc, char * argv[]) {
    FILE * f1, * f2;

    if(argc >= 3) {
        if(f1 = fopen(argv[1], "r")) {
            if(f2 = fopen(argv[2], "r")) {
                printf("%d\n", diff(f1, f2));
                fclose(f1); fclose(f2);
            } else {
                printf("Error opening file 2\n");
                fclose(f1);
            }
        } else
            printf("Error opening file 1\n");
    } else
        printf("Not enough args\n");

    return 0;
}

int diff(FILE * f1, FILE * f2) {
    int eq;
    char c1, c2;

    eq = 1;
    c1 = getc(f1);
    c2 = getc(f2);
    while(!feof(f1) && !feof(f2) && eq) {
        eq = c1==c2;
        c1 = getc(f1);
        c2 = getc(f2);
    }

    if((c1==EOF && c2!=EOF) || (c1!=EOF && c2==EOF))
        eq = 0;

    printf("\n%d\t\n", eq);

    return eq;
}
