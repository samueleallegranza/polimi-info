#include <stdio.h>
#include <string.h>
#define SPACE ' '
#define CR 0x0D
#define LF 0x0A
#define MAXLEN 100

int valid_chars(char []);

int main(int argc, char * argv[]) {
    FILE * fp;
    int nrows, nchars, maxchars, curr_chars;
    float avgchars;
    char curr_str[MAXLEN+1], max_str[MAXLEN+1];

    if(argc >= 2) {
        if(fp = fopen(argv[1], "r")) {
            nrows = 0; nchars = 0; maxchars = -1;
            while(fgets(curr_str, MAXLEN, fp) != NULL) {
                curr_chars = valid_chars(curr_str);
                if(curr_chars > maxchars) {
                    maxchars = curr_chars;
                    strcpy(max_str, curr_str);
                }
                nrows++;
                nchars += curr_chars;
            }
            fclose(fp);
            avgchars = (float) nchars / nrows;
            printf("%d\n%d\n%d %.0f\n%s\n", nrows, nchars, maxchars, avgchars, max_str);
        } else
            printf("Error while opening %s\n", argv[1]);
    } else
        printf("Not enough infos.\n");

    return 0;
}


int valid_chars(char str[]){
    int count, i;

    count = 0;
    for(i=0; str[i]!='\0'; i++)
        if((str[i] != SPACE) && (str[i] != CR) && (str[i] != LF)) {
            count++;
            printf("[%x] - c: %d\n", str[i], count);
        }

    return count;
}
