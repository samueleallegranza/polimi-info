#ifndef LISTI_H
#define LISTI_H

typedef struct listi_s {
    int v;
    struct listi_s * next;
} listi_t;

/* Insert ahead of list */
listi_t * push(listi_t * h, int val);

/* Insert at the end of list */
listi_t * append(listi_t * h, int val);

/* Remove element ahead of list */
//listi_t * pop(listi_t * h, int val);

/* Delete every element of the list with the specified value */
listi_t * delete_all(listi_t * h, int val);

/* Delete the first element of the list with the specified value */
//listi_t * delete(listi_t * h, int val);

/* Clear the list */
//listi_t * freelist(listi_t * h);

/* Calculate length of list */
int list_len(listi_t * h);

/* Print the elements of the list */
void print_list(listi_t * h);

#endif
