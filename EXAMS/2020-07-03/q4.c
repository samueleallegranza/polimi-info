#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDLEN 30
#define ARGV_SRC 1
#define ARGV_DST 2
#define ARGV_VOC 3

int ometti(char [], char [], char []);
void str_tolower(char []);

int main(int argc, char * argv[]) {
    char * fn_src, * fn_dst, * voc;
    int rms;

    if(argc >= (ARGV_VOC+1)) {
        fn_src = argv[ARGV_SRC];
        fn_dst = argv[ARGV_DST];
        voc = argv[ARGV_VOC];
        rms = ometti(fn_src, fn_dst, voc);
        printf("%d\n", rms);
    } else {
        printf("Argc not valid.\n");
    }

    return 0;
}

int ometti(char src[], char dst[], char voc[]) {
    FILE * fs, * fd;
    int isfirst, count;
    char word[MAX_WORDLEN + 1], word_low[MAX_WORDLEN + 1];

    str_tolower(voc);
    count = -1; // error case
    if(fs = fopen(src, "r")) {
        if(fd = fopen(dst, "w")) {
            isfirst = 1;
            count = 0;
            while(fscanf(fs, "%s", word) != EOF) {
                strcpy(word_low, word);
                str_tolower(word_low);
                if(strcmp(word_low, voc) == 0)
                    count++;
                else {
                    if(isfirst)
                        isfirst = 0;
                    else
                        fprintf(fd, " ");
                    fprintf(fd, "%s", word);
                }
            }
            fclose(fd);
            fclose(fs);
        } else {
            fclose(fs);
            printf("ERROR\n");
        }
    } else {
        printf("ERROR\n");
    }

    return count;
}

void str_tolower(char str[]){
    int i;
    for(i=0; str[i]!='\0'; i++)
        str[i] = tolower(str[i]);
}
