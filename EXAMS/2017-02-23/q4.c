#include <stdio.h>
#include "../../lib/listi.c"

listi_t * mixlists(listi_t *, listi_t *);

int main(int argc, char * argv[]) {
    listi_t * h1 = NULL;
    listi_t * h2 = NULL;
    listi_t * res = NULL;

    h1 = append(h1, 1);
    h1 = append(h1, 3);
    h1 = append(h1, 5);
    h1 = append(h1, 7);
    h1 = append(h1, 9);
    h1 = append(h1, 11);
    print_list(h1);

    h2 = append(h2, 2);
    h2 = append(h2, 4);
    h2 = append(h2, 6);
    h2 = append(h2, 8);
    print_list(h2);

    res = mixlists(h1, h2);
    print_list(res);

    return 0;
}

listi_t * mixlists(listi_t * p1, listi_t * p2){
    listi_t * res = NULL;
    listi_t * e1, * e2;

    e1 = p1;
    e2 = p2;
    while(e1 != NULL && e2 != NULL) {
        res = append(res, e1->v);
        res = append(res, e2->v);
        e1 = e1->next;
        e2 = e2->next;
    }

    if(e1 == NULL && e2 !=NULL) {
        while(e2!=NULL) {
            res = append(res, e2->v);
            e2 = e2->next;
        }
    } else if(e1 != NULL && e2 == NULL) {
        while(e1 != NULL) {
            res = append(res, e1->v);
            e1 = e1->next;
        }
    }

    return res;
}
