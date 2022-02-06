// This is an adapted version of the exercise using integers
// instead of chars (see defines below to translate)
#include <stdio.h>
#include "../../lib/listi.c"
#define OP_BR 6
#define CL_BR 9
#define HASH 888

listi_t * subsq(listi_t *);

int main(int argc, char * argv[]) {
    listi_t * li;

    li = append(li, 1);
    li = append(li, 2);
    li = append(li, 3);
    li = append(li, OP_BR);
    li = append(li, CL_BR);
    li = append(li, 1);
    li = append(li, 2);
    li = append(li, 1);
    li = append(li, OP_BR);
    li = append(li, 8);
    li = append(li, 7);
    li = append(li, CL_BR);
    li = append(li, 5);
    print_list(li);

    li = subsq(li);
    print_list(li);

    return 0;
}

listi_t * subsq(listi_t * h) {
    listi_t * p, * cl, * op, * rem;

    p = h;
    while(p != NULL) {
        if(p->v == OP_BR) {
            op = p;
            cl = p->next;
            while(cl->v != CL_BR) {
                rem = cl;
                cl = cl->next;
                free(rem);
            }
            p = cl;
            p = push(p, HASH);
            op->next = p;
            p = cl;
        } else {
            p = p->next;
        }
    }

    return h;
}
