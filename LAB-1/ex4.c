#include <stdio.h>
#define BLOCK '#'
#define H_LIMIT 16

int main(int argc, char * argv[]) {
    int h;
    int blocks, blank;
    int i,j;

    do {
        scanf("%d", &h);
    } while(h<=0 || h>H_LIMIT);

    for(i=0; i<h; i++) {
        blocks = i+1;
        blank = h-blocks;

        for(j=0; j<blank; j++) {
            printf(" ");
        }
        for(j=0; j<blocks; j++) {
            printf("%c", BLOCK);
        }
        printf("  ");
        for(j=0; j<blocks; j++) {
            printf("%c", BLOCK);
        }
        for(j=0; j<blank; j++) {
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}