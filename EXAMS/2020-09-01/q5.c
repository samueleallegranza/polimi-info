#include <stdio.h>
#include "../../lib/listi.c"

listi_t * check_missing(listi_t *);
int exists(listi_t *, int);

int main(int argc, char * argv[]) {
    listi_t * l = NULL;
    listi_t * m = NULL;

    l = append(l, -2);
    l = append(l, 0);
    l = append(l, 1);
    l = append(l, 3);
    l = append(l, 5);
    print_list(l);

    m = check_missing(l);
    print_list(m);

    return 0;
}

listi_t * check_missing(listi_t * codici) {
    int i;
    int min, max;
    listi_t * p;
    listi_t * missing = NULL;

    if(codici == NULL)
        return missing;
    else {
        p = codici;
        min = p->v;
        max = p->v;
        p = p->next;
        while(p) {
            if(p->v > max) max=p->v;
            if(p->v < min) min=p->v;
            p = p->next;
        }
        for(i=min; i<=max; i++)
            if(!exists(codici, i))
                missing = append(missing, i);
        return missing;
    }
}

int exists(listi_t * h, int n) {
    listi_t * p;
    int found;

    found = 0;
    p = h;
    while(!found && p!=NULL){
        found = (n == p->v);
        p = p->next;
    }

    return found;
}
