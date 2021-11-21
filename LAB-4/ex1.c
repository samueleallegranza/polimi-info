#include <stdio.h>
#define FN_MAXLEN 50

void file_copy(FILE *, FILE *);

int main(int argc, char * argv[]) {
    FILE * fin1, * fin2, * fout;
    char fn_in1[FN_MAXLEN], fn_in2[FN_MAXLEN], fn_out[FN_MAXLEN];
    int direction;

    scanf("%s%s%s", fn_in1, fn_in2, fn_out);
    scanf("%d", &direction);

    if(direction == 0) {
        fin1 = fopen(fn_in1, "r");
        fin2 = fopen(fn_in2, "r");
    } else {
        fin1 = fopen(fn_in2, "r");
        fin2 = fopen(fn_in1, "r");
    }

    fout = fopen(fn_out, "w");

    if(fin1 && fin2) {
        if(fout) {
            file_copy(fin1, fout);
            file_copy(fin2, fout);
            fclose(fout);
        } else {
            printf("Error opening %s", fn_out);
        }
        fclose(fin1);
        fclose(fin2);
    } else {
        printf("Error opening %s or %s (or both)", fn_in1, fn_in2);
    }

    return 0;
}

void file_copy(FILE * from, FILE * to) {
    char c;
    while(fscanf(from, "%c", &c) != EOF)
        fprintf(to, "%c", c);
}
