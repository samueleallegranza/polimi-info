/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un programma che acquisisca 5 numeri interi da
    tastiera (sicuramente distinti) e li inserisca in una lista.
    Il programma chiede poi all'utente un ulteriore numero N e
    se questo e' presente nella lista lo rimuove e aggiunge in
    fondo alla lista il suo quadrato.
    Si assuma di avere a disposizione i seguenti sottoprogrammi
    (oltre a quelli gia' visti a lezione):
    - listint_t * search(listint_t *, int) che ricevuto in ingresso
    la testa di una lista ed un valore da cercare ritorna il primo
    riferimento al nodo della lista con il valore cercato.
    Se l'elemento non compare la funzione ritorna NULL.
    - listint_t * delete(listint_t *, int) che ricevuto in ingresso
    la testa di una lista ed un valore da eliminare (sapendo che questo
    esiste ed e' unico) lo rimuova dalla lista e ritorni al chiamante
    la testa della lista modificata.
*/
#include <stdio.h>
#define DIM 5

typedef struct listint_s {
    int v;
    listint_s * next;
} listint_t;

listint_t * append(listint_t *, int);
listint_t * search(listint_t *, int);

int main(int argc, char * argv[]) {
    listint_t * head = NULL;
    int i, val;

    for(i=0; i<DIM; i++) {
        scanf("%d", &val);
        head = append(head, val);
    }

    scanf("%d", &val);
    if(search(head, val) != NULL) {
        head = delete(head, val);
        head = append(head, v*v);
    }

    return 0;
}

listint_t * append(listint_t * h, int v){
    listint_t * p, * tmp;

    if(p = malloc(sizeof(listint_t))) {
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

listint_t * search(listint_t * h, int search) {
    listint_t * curr;

    curr = h;
    while(curr != NULL) {
        if(curr->v == search)
            return curr;
        curr = curr->next;
    }

    return NULL;
}
