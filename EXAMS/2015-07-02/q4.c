#include <stdio.h>
#define FN_MAX 80
#include "../../lib/listi.c"

int main(int argc, char * argv[]) {

    char fn[FN_MAX];
    FILE * fp;
    int prev, curr;
    listi_t * h = NULL;

    scanf("%s", fn);
    if(fp = fopen(fn, "r")) {
        fscanf(fp, "%d%d", &prev, &curr);
        while(!feof(fp)) {
            if(curr != prev+1)
                h = append(h, prev+1);
            prev = curr;
            fscanf(fp, "%d", &curr);
        }
        print_list(h);
        fclose(fp);
    } else {
        printf("Errore apertura con il file %s", fn);
    }


    return 0;
}
