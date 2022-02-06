#include <stdio.h>
#include "../../lib/listi.c"

int isprime(int);
listi_t * rm_abs(listi_t * h);

int main(int argc, char * argv[]) {
    listi_t * h = NULL;
    h = append(h, 13);
    h = append(h, 7);
    h = append(h, 6);
    h = append(h, 13);
    h = append(h, 8);
    h = append(h, 13);
    print_list(h);
    h = rm_abs(h);
    print_list(h);

    return 0;
}

listi_t * rm_abs(listi_t * h){
    listi_t * prev, * curr, * tmp;
    int front;

    if(h != NULL) {
        front = 1;
        while(front && h!=NULL) {
            if(isprime(h->v)) {
                curr = h;
                h = h->next;
                free(curr);
            } else {
                front = 0;
            }
            print_list(h);
        }
        prev = h;
        curr = h->next;
        while(curr!=NULL) {
            if(isprime(curr->v)) {
                tmp = curr;
                curr = curr->next;
                prev->next = curr;
                free(tmp);
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    return h;
}

int isprime(int a){
    int c;
    for(c = 2; c<=a-1; c++){
        if(a%c == 0)
            return 0;
   }
   return 1;
}
