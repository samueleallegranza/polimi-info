#include <stdio.h>
#include <stdlib.h>

#include "listi.h"

#define ERR_ALLOC "Memory allocation error"

listi_t * push(listi_t * h, int v) {
    listi_t * new;

    new = malloc(sizeof(listi_t));
    if(new) {
        new->v = v;
        new->next = h;
        h = new;
    } else {
        printf("%s", ERR_ALLOC);
    }

    return h;
}

listi_t * append(listi_t * h, int v) {
    listi_t * new;
    listi_t * p;

    new = malloc(sizeof(listi_t));
    if(new) {
        new->v = v;
        new->next = NULL;
        if(h == NULL) {
            h = new;
        } else {
            p = h;
            while(p->next != NULL)
                p = p->next;
            p->next = new;
        }
    } else {
        printf("%s", ERR_ALLOC);
    }

    return h;
}

int list_len(listi_t * h) {
    int count;
    listi_t * p;

    count = 0;
    p=h;
    while(p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

listi_t * delete_all(listi_t * h, int n) {
    listi_t * p, *prev;

    p=h;
    while(p != NULL && p->v == n){
        h = p->next;
        free(p);
        p = h;
    }
    if(p != NULL) {
        prev = p;
        p = p->next;
        while(p!=NULL) {
            if(p->v == n) {
                prev->next = p->next;
                free(p);
                p = prev->next;
            } else {
                p = p->next;
                prev = prev->next;
            }
        }
    }

    return h;
}

void print_list(listi_t * h) {
    listi_t * p;

    if(h == NULL) {
        printf("Empty.\n");
    } else {
        p = h;
        while(p != NULL) {
            printf("[%d]->", p->v);
            p = p->next;
        }
        printf("\n");
    }
}
