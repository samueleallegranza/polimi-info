/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma listapicchi che ricevta in
    ingresso una lista ne restituisce una nuova costituita da
    tutti e soli gli elementi della prima lista seguiti solo
    da elementi con un valore strettamente inferiore a quello
    dell'elemento stesso.
    L'ultimo elemento della lista viene messo nella nuova lista
    creata.
    Per esempio se la lista in ingresso e'
    1 -> 5 -> 13 -> 11 -> 11 -> 4 -> 3 -> 1 -> -5
    La lista restituita conterra':
    13 -> 11 -> 4 -> 1 -> -5
    Si considerino gia disponibili le funzioni gia vista a
    lezione per la gestione di liste di interi.
    Variante: Scrivere una variante del sottoprogramma
    listapicchi che non inserisce nella lista dei picchi
    l'ultimo elemento della lista ricevuta in ingresso
*/
#include <stdio.h>
#include <stdlib.h>

listi_t * listapicchi(listi_t *);
listi_t * listapicchi_var(listi_t *);

listi_t * listapicchi(listi_t * h){
    listi_t * p;
    listi_t * res = NULL;

    p=h;
    while(p!=NULL && p->next!=NULL) {
        if(p->next->v < p->v)
            append(res, p);
        p = p->next;
    }

    if(p!=NULL)
        append(res, p); // Last element always in new list

    return res;
}

listi_t * listapicchi_var(listi_t * h) {
    listi_t * p;
    listi_t * res = NULL;

    p=h;
    while(p!=NULL && p->next!=NULL) {
        if(p->next->v < p->v)
            append(res, p);
        p = p->next;
    }
    // Last element ignored

    return res;
}
