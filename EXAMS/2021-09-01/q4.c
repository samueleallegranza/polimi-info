#include <stdio.h>
#define MAX_USR 20
#define LEN_MIN 8
#define LEN_MAX 15

int valido(char [], int, int, char []);
int contains(char [], char);
void StartApp(char []);

int main(int argc, char * argv) {
    char spec[] = "$#%&";
    char usr[MAX_USR + 1];

    do {
        scanf("%s", usr);
    } while(!valido(usr, LEN_MIN, LEN_MAX, spec));

    StartApp(usr);

    return 0;
}


int valido(char usrname[], int min, int max, char spec[]) {
    int len, spec_ok;

    spec_ok = 0;
    len = 0;
    while(usrname[len]!='\0' && len<max) {
        spec_ok = contains(spec, usrname[len]);
        len++;
    }

    return (spec_ok && (len>=min && len<=max));
}

int contains(char symb[], char c) {
    int i;

    i=0;
    while(symb[i]!='\0' && symb[i]!=c)
        i++;

    // If not contained, string terminator is compared to c
    return (symb[i] == c);
}

void StartApp(char usr[]) {
    printf("\nLogged in with username [%s]!\n\tApp started.\n\n", usr);
}
