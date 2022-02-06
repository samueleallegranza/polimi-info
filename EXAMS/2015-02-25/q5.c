#include <stdio.h>
#include "../../lib/listi.c"

int len_before_val(listi_t *, int);

int main(int argc, char * argv[]) {
    listi_t * h = NULL;
    h = append(h, 1);
    h = append(h, 2);
    h = append(h, 3);
    h = append(h, 4);
    print_list(h);
    printf("%d\n", len_before_val(h, 4));
    return 0;
}

int len_before_val(listi_t * h, int target) {
    if(h->v == target)
        return 0;
    else
        return 1 + len_before_val(h->next, target);
}
