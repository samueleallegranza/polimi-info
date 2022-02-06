#include <stdio.h>
#include "../../lib/listi.c"
#define ARG_V 1
#define PUSH 0
#define APPEND 1
#define BASE 10

listi_t * int2list(int val);

int main(int argc, char * argv[]) {
    listi_t * list = NULL;

    if(argc >= (ARG_V+1)) {
        list = int2list(atoi(argv[ARG_V]));
        print_list(list);
    } else
        printf("Error.\n");

    return 0;
}

listi_t * int2list(int val) {
    int mode, dig, i;
    listi_t *h, *p;
    h = NULL;

    if(val<0) {
        mode = APPEND;
        val = -val;
    } else
        mode = PUSH;

    while(val>0) {
        dig = val%BASE;
        for(i=0; i<dig; i++) {
            if(mode == PUSH) {
                h = push(h, dig);
            } else if(mode == APPEND) {
                if(h == NULL) {
                    h = append(h, dig);
                    p = h;
                } else {
                    p = append(p, dig); // reduces workload
                    p = p->next;
                }
            }
        }
        val /= BASE;
    }

    return h;
}
