#include <stdio.h>
#include "../../lib/listi.c"

int kcon(listi_t * h, int k) {
    if(h != NULL && h->next!=NULL)
        if((h->v == h->next->v) && (h->v == k))
            return 1;
        else
            return kcon(h->next, k);
    else
        return 0;
}

int main(int argc, char * argv[]) {
    listi_t * li;

    li = append(li, 1);
    li = append(li, 10);
    li = append(li, 8);
    li = append(li, 6);
    li = append(li, 6);
    li = append(li, 10);
    li = append(li, 10);
    print_list(li);

    printf("%d\n", kcon(li, 10));

    return 0;
}
