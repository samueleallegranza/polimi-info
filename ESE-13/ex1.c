/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma scomponi che rievuto in ingresso
    un numero intero senz'altro strettamente positivo n lo
    scompone e restituisce al chiamante i fattori. Realizare
    un'opportuna struttura dati.
    Ad esempio, per n=60 il programma trasmette i valori 2 2 3 5.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct listi_s {
    int v;
    struct listi_s * next;
} listi_t;

listi_t * scomponi(int);
listi_t * append(listi_t *, int);

int main(int argc, char * argv[]) {
    listi_t * res;
    res = scomponi(60);
    return 0;
}


listi_t * scomponi(int n) {
    int div;
    listi_t * head = NULL;

    while(n>1) {
        div = 2;
        while(n%div!=0)
            div++;
        append(head, div);
        printf("%d\n", div);
        n /= div;
    }

    return head;
}


listi_t * append(listi_t * h, int v){
    listi_t * p, * tmp;

    if(p = malloc(sizeof(listi_t))) {
        p->v = v;
        p->next = NULL;
        if(h == NULL) {     // lista vuota
            h = p;
        } else {            // lista non vuota
            tmp = h;
            while(tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = p;
        }
    } else
        printf("[append] memory allocation error\n");

    return h;
}
