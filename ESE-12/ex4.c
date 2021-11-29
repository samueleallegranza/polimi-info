/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si implementi il sottoprogramma listint_t * delete(listint_t *, int)
    che ricevuto in ingresso la testa di una lista ed un valore da
    eliminare (sapendo che questo esiste ed e' unico) lo rimuova dalla
    lista e ritorni al chiamante la testa della lista modificata.
*/

listint_t * delete(listint_t *, int);

listint_t * delete(listint_t * h, int del) {
    listint_t * curr, * todel;

    if(h == NULL)
        return NULL;

    if(h->v == del) {
        todel = h;
        h = h->next;
        free(todel);
    } else {
        curr = h;
        while(curr != NULL && curr->next != NULL) {
            if(curr->next->v == del) {
                todel = curr->next;
                curr->next = todel->next;
                free(todel);
                return h;
            }
            curr = curr->next;
        }
    }

    return h;
}
