/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un sottoprogramma extract che riceve in ingresso
    una lista per la gestione dei numeri interi e un intero start
    che vale senz'altro 1 o 0 (non e' necessario gestire il caso
    in cui non sia cosi).
    La lista codifica un'informazione binaria: il valore del primo
    elemento indica quante volte consecutive compare il bit start,
    il secondo elemento indica quante volte compare il complemento
    di start, il terzoe elemento indica quante volte compare il bit
    di start e cosi via fino alla fine della lista.
    Il sottoprogramma scompatta tale informazione e restituisce una
    nuova lista i cui elementi contengono ciascuno 0 o 1.
    Non e' necessario definire due tipi diversi di dato, poiche' il
    contenuto dell'elemento della lista e' comunque sempre un
    intero.
    Per esempio: se la lista in ingresso e' quella di seguito e il
    bit di start e' 1:
    3 -> 5 -> 1 -> 2 -> 2 -> 1 -> |
    Il sottoprogramma restituisce la lista seguente
    1->1->1->0->0->0->0->0->1->0->0->1->1->0->|
    Si considerino gia disponibili le funzioni gia viste a lezione
    per la gestione di liste di interi.
*/
#include <stdio.h>
#include <stdlib.h>

listi_t * extract(listi_t *, int);

listi_t * extract(listi_t * h, int start){
    listi_t * p;
    listi_t * res = NULL;
    int i, bit;

    p=h;
    bit = start;
    while(p) {
        for(i=0; i<(p->v); i++)
            append(res, bit);
        bit = !bit;
        p = p->next;
    }

    return res;
}
