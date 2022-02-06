#include <stdio.h>
#include "../../lib/listi.c"

listi_t * complete_order(listi_t *);
listi_t * insert_inc(listi_t *, int);

int main(int argc, char * argv[]) {
    listi_t * h = NULL;

    h = append(h, -3);
    h = append(h, 1);
    h = append(h, 6);
    print_list(h);

    h = complete_order(h);
    print_list(h);

    return 0;
}

listi_t * complete_order(listi_t * h){
    int prev, succ, i;
    listi_t * new, * p;

    if(h != NULL) {
        p = h;
        prev = p->v;
        p = p->next;
        while(p!=NULL) {
            succ = p->v;
            for(i=(prev+1); i<succ; i++)
                insert_inc(h, i);
            prev = succ;
            p = p->next;
        }
    }

    return h;
}

listi_t * insert_inc(listi_t * h, int n) {
    listi_t * p, * prv;
    listi_t * new;

    new = malloc(sizeof(listi_t));
    new->next = NULL;
    new->v = n;

    if(h == NULL) {
        h = new;
    } else if(h->v > n){
        new->next = h;
        h = new;
    } else {
        prv = h;
        p = h->next;
        while(p!=NULL && (p->v < n)) {
            prv = prv->next;
            p = p->next;
        }
        prv->next = new;
        new->next = p;
    }

    return h;
}
