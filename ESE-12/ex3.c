/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si implementi il programma listint_t * search(listint_t *, int)
    che ricevuto in ingresso la testa di una lista ed un valore
    da cercare ritorna il primo riferimento al nodo della lista con
    il valore cercato.
    Se l'elemento non compare la funzione ritorna NULL.
*/

listint_t * search(listint_t *, int);

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
