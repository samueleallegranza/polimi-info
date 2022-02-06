#include <stdio.h>
#include "../../lib/listi.c"

listi_t * delfromlist(listi_t *, int);
listi_t * delete_all(listi_t *, int);

int main(int argc, char * argv[]) {

    listi_t * l = NULL;

    l = append(l, 101);
    l = append(l, 101);
    l = append(l, 1);
    l = append(l, 106);
    l = append(l, 106);
    l = append(l, 106);
    l = append(l, 2);
    l = append(l, 4);
    l = append(l, 101);
    l = append(l, 5);
    l = append(l, 101);
    l = append(l, 5);
    l = append(l, 4);
    l = append(l, 4);
    print_list(l);
    l = delfromlist(l, 3);
    print_list(l);

    return 0;
}


listi_t * delfromlist(listi_t * h, int x) {
    int rep;
    listi_t * scan, * nh, * p;

    scan = h;
    while(scan!=NULL) {
        rep = 1;
        p = scan->next;
        while(p!=NULL && rep<x) {
            if(p->v == scan->v)
                rep++;
            p = p->next;
        }
        if(rep >= x) {
            nh = delete_all(h, scan->v);
            if(nh != h)
                scan = nh;
            else
                scan = scan->next;
            h = nh;
        } else
            scan = scan->next;
    }

    return h;
}
