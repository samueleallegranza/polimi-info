#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PHRASE_ENDING '.'
#define SPACE ' '
#define FN_LEN 40
#define ROW_LEN 200

void line_stats(char[], int *, int *, int *);

int main(int argc, char * argv[]) {
    int min, max;
    int rows;
    int phrases;
    FILE * fp;
    char row[ROW_LEN + 1];
    char filename[FN_LEN+1];

    scanf("%s", filename);
    if(fp=fopen(filename, "r")) {
        rows = 0;
        phrases = 0;
        min = -1;       // -1 will be replaced
        max = -1;       // -1 will be replaced

        while(fgets(row, ROW_LEN, fp)) {
            line_stats(row, &phrases, &min, &max);
            rows++;
        }

        fclose(fp);
        printf("max: %d\nmin: %d\nrighe: %d\nfrasi: %d\n", max, min, rows, phrases);
    } else
        printf("ERROR\n");

    return 0;
}

void line_stats(char row[], int * phr, int * min, int * max){
    int i, c;
    c=0;
    for(i=0; row[i]!='\0' && row[i]!='\n'; i++){
        *(phr) += (row[i] == PHRASE_ENDING);
        if(row[i] != SPACE) {
            c++;
            printf("[%c]", row[i]);
        }
    }
    printf("\n");

    if(c<*(min) || *(min)==-1)
        *(min) = c;
    if(c>*(max) || *(max)==-1)
        *(max) = c;
}
