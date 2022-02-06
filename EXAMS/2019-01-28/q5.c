#include <stdio.h>
#include <ctype.h>
#define N_COUNT 9

int file_val(FILE *);

int main(int argc, char * argv[]) {
    FILE * fp;

    if(argc>1) {
        if(fp = fopen(argv[1], "r")) {
            printf("%d\n", file_val(fp));
            printf("%d\n", file_val(fp));
            printf("%d\n", file_val(fp));
            fclose(fp);
        } else {
            printf("Error.\n");
        }
    } else {
        printf("Args not valid.\n");
    }

    return 0;
}

int file_val(FILE * fp) {
    char vc;
    int counter[N_COUNT]; // counters 0-9
    int v, i, ended, maxc, maxv;

    for(i=0 ;i<N_COUNT; i++)
        counter[i] = 0;

    ended = 0;
    for(i=0; !ended; i++) {
        vc = getc(fp);
        if(isdigit(vc)) {
            v = vc - '0';
            counter[v]++;
        } else
            ended = 1;
    }

    maxc = 0;
    maxv = -1;
    for(i=0; i<N_COUNT; i++)
        if((counter[i]>maxc) || ((counter[i]==maxc) && (maxv<i) && (maxv!=-1))) {
            maxc = counter[i];
            maxv = i;
        }

    return maxv;
}
