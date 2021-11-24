/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma che riceve in ingresso una stringa
    contenente un paragrafo di testo scritto in italiano.
    Il sottoprogramma modifica la stringa eliminando da essa tutti
    i segni di interpunzione, ossia quei caratteri che differiscono
    dai caratteri 'a'-'z', 'A'-'Z', '0'-'9' e spazio.
    Il sottoprogramma restituisce il numero di caratteri eliminati
    E' garantito che nel testo iniziale ci siano tutti e soli
    caratteri 'a'-'z', 'A'-'Z', '0'-'9', spazi e segni di
    interpunzione.
*/
#include <stdio.h>
#include <stdlib.h>
#define S_NUM '0'
#define E_NUM '9'
#define S_UPPER 'A'
#define E_UPPER 'Z'
#define S_LOWER 'a'
#define E_LOWER 'z'
#define SPACE ' '

int clear_text(char * text);
int is_valid(char);

int main(int argc, char * argv[]) {
    char text[] = "La Wanderlust indica il desiderio di andare altrove, di andare oltre il proprio mondo, di cercare qualcos'altro: un desiderio di esotismo, scoperta e viaggio. ";
    int in_len, out_len;

    out_len = clear_text(text);
    printf("%s\nRemoved: %d\n", text, out_len);

    return 0;
}

int clear_text(char text[]){
    int i, j;
    for(i=0, j=0; text[i]!='\0'; i++) {
        if(is_valid(text[i])) {
            text[j] = text[i];
            j++;
        }
    }
    text[j] = '\0';
    return (i-j);
}

int is_valid(char c) {
    return ((c>=S_NUM && c<=E_NUM) || (c>=S_UPPER && c<=E_UPPER) || (c>=S_LOWER && c<=E_LOWER) || c==SPACE);
}
