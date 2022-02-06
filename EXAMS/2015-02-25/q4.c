#include <stdio.h>
#define FN_LEN 80
#define END_SPECIAL_ASCII 31

int main(int argc, char * argv[]) {
    int eq;
    char filename1[FN_LEN], filename2[FN_LEN];
    char c1, c2;
    FILE * fp1, *fp2;

    scanf("%s", filename1);
    scanf("%s", filename2);
    if(fp1 = fopen(filename1, "r")){
        if(fp2 = fopen(filename2, "r")) {

            eq = 0;
            c1 = getc(fp1);
            c2 = getc(fp2);
            if(!feof(fp1) && !feof(fp2)){
                do {
                    if((c1==c2) && (c1>END_SPECIAL_ASCII))
                        eq++;
                    c1 = getc(fp1);
                    c2 = getc(fp2);
                } while(!feof(fp1) && !feof(fp2));
            }
            fclose(fp1); fclose(fp2);

            if(c1==EOF && c2==EOF) {
                printf("---\n");
            } else if(c1!=EOF && c2==EOF){
                printf("%s\n", filename1);
            } else {
                printf("%s\n", filename2);
            }
            printf("%d\n", eq);
        } else {
            fclose(fp1);
            printf("Errore apertura file %s\n", filename2);
        }
    } else {
        printf("Errore apertura file %s\n", filename1);
    }

    return 0;
}
