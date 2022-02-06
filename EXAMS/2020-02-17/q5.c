#include <stdio.h>
#include "../../lib/listi.c"

listi_t * elem_rev(listi_t *, int);

int main(int argc, char * argv[]) {
    listi_t * h = NULL;
    listi_t * elem;
    int target;

    h = append(h, 1);
    h = append(h, 2);
    h = append(h, 3);
    h = append(h, 4);
    print_list(h);

    target = 1;
    if((elem = elem_rev(h, target)) != NULL) {
        printf("%d\n", elem->v);
    }

    return 0;
}

listi_t * elem_rev(listi_t * h, int target) {
    int len;
    listi_t * p;
    int idx;

    len = list_len(h);
    if(target>0 && target<=len) {
        idx=len;
        p=h;
        while(idx != target) {
            p = p->next;
            idx--;
        }
        return p;
    } else {
        return NULL;
    }
}
