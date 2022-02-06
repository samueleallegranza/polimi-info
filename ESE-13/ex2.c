/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma selectitems che ricevuta in
    ingresso una lista per la gestione di valori interi e
    due interi min e max, crea una nuova lista contente
    tutti e soli i valori presenti nella list di ingresso
    strettamente compresi tra min e max, ordinati in modo
    crescente e la restituisce al chiamante.
    La lista di partenza non deve essere modificata.
    Si considerino dati i sottoprogrammi di gestione delle
    liste visti a lezione.
*/
#include <stdio.h>
#include <stdlib.h>

listi_t * selectitems(listi_t *, int, int);

listi_t * selectitems(listi_t * h, int min, int max) {
    listi_t * res;
    listi_t * p;

    p = h;
    while(p) {
        if((h->v) > min && (h->v) < max) {
            res = insertup(h2, h->v);
        }
        p = p->next;
    }

    return res;
}
