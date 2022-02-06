#include <stdio.h>
#include "../../lib/listi.c"

listi_t * compact_list(listi_t *);

int main(int argc, char * argv[]) {
    listi_t * l = NULL;

    l = append(l, 0);
    l = append(l, 1);
    l = append(l, 3);
    l = append(l, 5);
    l = append(l, -2);
    l = append(l, 3);
    l = append(l, -1);
    l = append(l, 0);
    l = append(l, 2);
    l = append(l, 4);
    l = append(l, 1);
    print_list(l);

    l = compact_list(l);
    print_list(l);

    return 0;
}

listi_t * compact_list(listi_t * h) {
    listi_t *p, *scan;

    h = delete_all(h, 0);
    scan = h;
    while(scan != NULL) {
        p = scan->next;
        p = delete_all(p, scan->v);
        scan->next = p;
        scan = scan->next;
    }

    return h;
}
