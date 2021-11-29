/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma listint_t * freelist(listint_t *) che
    ricevuto il puntatore ad una lista, liberi tutto lo spazio
    allocato in memoria relativo allla lista data. La funzione
    ritorna il puntatore alla testa della lista, che corrispondera'
    a NULL (lista vuota).
*/
#include <stdio.h>

typedef struct listint_s {
    int v;
    listint_s * next;
} listint_t;

listint_t * freelist(listint_t *);

listint_t * freelist(listint_t * h){
    listint_t * tmp;
    while(h != NULL) {
        tmp = h;
        h = h->next;
        free(tmp);
    }
    return h;
}
