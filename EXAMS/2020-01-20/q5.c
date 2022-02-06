#include <stdio.h>
#include "../../lib/listi.c"

#define SX 0
#define DX 1

//typedef struct listi_s {
//    int val;
//    struct listi_s * next;
//} listi_t;

listi_t * rotate_sx(listi_t *);
listi_t * rotate_dx(listi_t *);
listi_t * rotate(listi_t *, int);

int main(int argc, char * argv[]) {
    listi_t * h = NULL;
    h = append(h, 3);
    h = append(h, 6);
    h = append(h, 10);
    h = append(h, -2);
    h = append(h, 8);
    print_list(h);

    h = rotate(h, SX);
    print_list(h);
    h = rotate(h, SX);
    print_list(h);
    h = rotate(h, DX);
    print_list(h);

    return 0;
}

listi_t * rotate(listi_t * h, int dir) {
    if(dir == SX)
        h = rotate_sx(h);
    else
        h = rotate_dx(h);

    return h;
}

listi_t * rotate_sx(listi_t * h) {
    listi_t * new;
    listi_t * p;

    // Works also with only one value in list
    if(h != NULL) {
        p=h;
        while(p->next != NULL)
            p = p->next;

        p->next = h;
        h = (p->next)->next;
        (p->next)->next = NULL;
    }

    return h;
}

listi_t * rotate_dx(listi_t * h) {
    listi_t * new;
    listi_t * p;

    // Warning. If the list is empty the condition (h->next != NULL) tries
    // to access data that does not exist. It works, but it's better to put
    // these 2 conditions in nested constructs.
    if((h != NULL) && (h->next != NULL)) {
        p = h;
        while((p->next)->next != NULL)
            p = p->next;

        (p->next)->next = h;
        h = (p->next);
        p->next = NULL;
    }

    return h;
}
