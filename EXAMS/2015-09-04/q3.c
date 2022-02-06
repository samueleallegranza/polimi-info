#include <stdio.h>
#define FN_LEN 80
#define NUM_START '0'
#define NUM_END '9'

int charisnum(char);

int main(int argc, char * argv[]) {
    int count, aredigits;
    FILE * fp;
    char filename[FN_LEN], curr;

    scanf("%s", filename);
    if(fp = fopen(filename, "r")) {
        aredigits = 0;
        count = 0;
        while(!feof(fp)) {
            curr = fgetc(fp);
            if(charisnum(curr)) {
                if(!aredigits) {
                    aredigits = 1;
                    count++;
                }
            } else
                aredigits = 0;
        }
        fclose(fp);
        printf("%d\n", count);
    } else
        printf("Error.\n");

    return 0;
}

int charisnum(char c) {
    return (c >= NUM_START) && (c <= NUM_END);
}
