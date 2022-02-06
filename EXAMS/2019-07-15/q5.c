// Warning: not tested (yet)
// This is only the "raw" solution.
// Not compilable.

#include <stdio.h>
#include "../../listi.c"

typedef struct listocc_s {
    int v;
    int occ;
    struct listocc_s * next;
} listocc_t;

listocc_t * list_ord_occ(listi_t * h) {
    listi_t * p;
    listocc_t * occ, * curr;

    p = h;
    while(p!=NULL) {
        if(curr = occ_exists(occ, p->v)) {
            curr->occ += 1;
        } else {
            occ_increasing(occ, p->v);
        }
        p = p->next;
    }

    return occ;
}
