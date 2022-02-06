#include <stdio.h>
#define FN_OUT "ris.txt"

int div_prp(int);

int main(int argc, char * argv[]) {
    FILE * fp;
    int count, v;

    if(fp = fopen(FN_OUT, "w")) {
        count = 0;
        scanf("%d", &v);
        while(v>0) {
            fprintf(fp, "%d %d\n", v, div_prp(v));
            count++;
            scanf("%d", &v);
        }
        fclose(fp);
        printf("%d\n", count);
    } else
        printf("Error.\n");

    return 0;
}


int div_prp(int n) {
    int count, i;
    count = 0;
    for(i=2; i<=(n/2); i++)
        if(n%i == 0)
            count++;

    return count;
}
