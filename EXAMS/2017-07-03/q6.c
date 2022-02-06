#include <stdio.h>
#include <stdlib.h>

typedef struct _term {
    int c;
    int p;
    struct _term * next;
} t_term;

t_term * append(t_term *, int, int);
void print_list(t_term *);
t_term * sum(t_term *, t_term *);

int main(int argc, char * argv[]) {
    t_term * poly1 = NULL;
    t_term * poly2 = NULL;
    t_term * res = NULL;

    poly1 = append(poly1, 0, 3);
    poly1 = append(poly1, 2, 2);
    poly1 = append(poly1, 4, 1);
    poly1 = append(poly1, 6, 0);
    print_list(poly1);

    poly2 = append(poly2, -10, 4);
    poly2 = append(poly2, 1, 3);
    poly2 = append(poly2, 3, 2);
    poly2 = append(poly2, 5, 1);
    poly2 = append(poly2, 5, 0);

    printf("\n\n");
    res = sum(poly1, poly2);
    printf("\n\n");
    print_list(res);

    return 0;
}

t_term * sum(t_term * poly1, t_term * poly2) {
    t_term * res = NULL;
    t_term * p1, * p2;
    int i;

    p1 = poly1;
    p2 = poly2;
    if(p1 == NULL || p2 == NULL) {
        printf("An error occurred: polynomial is empty.");
    } else {

        while(p1 != NULL && p2 != NULL) {
            while((p1 != NULL) && (p1->p > p2->p)) {
                res = append(res, p1->c, p1->p);
                p1 = p1->next;
            }
            while((p2 != NULL) && (p2->p > p1->p)) {
                res = append(res, p2->c, p2->p);
                p2 = p2->next;
            }
            res = append(res, (p1->c + p2->c), p1->p);
            p1 = p1->next;
            p2 = p2->next;
            print_list(res);
        }

        if(p2==NULL && p1!=NULL){
            while((p1 != NULL) && (p1->p > p2->p)) {
                res = append(res, p1->c, p1->p);
                p1 = p1->next;
            }
        } else if(p1==NULL && p2!=NULL) {
            while((p2 != NULL) && (p2->p > p1->p)) {
                res = append(res, p2->c, p2->p);
                p2 = p2->next;
            }
        }

    }

    return res;
}

t_term * append(t_term * h, int c, int p) {
    t_term * e;
    t_term * new = NULL;

    new = malloc(sizeof(t_term));
    new->c = c;
    new->p = p;
    new->next = NULL;

    if(h==NULL) {
        h = new;
    } else {
        e = h;
        while(e->next != NULL)
            e = e->next;
        e->next = new;
    }

    return h;
}

void print_list(t_term * h) {
    t_term * e;

    e = h;
    if(e == NULL) {
        printf("Void.\n");
    } else {
        while(e != NULL) {
            printf("[%d x^%d] -> ", e->c, e->p);
            e = e->next;
        }
        printf("[NULL]\n");
    }
}
