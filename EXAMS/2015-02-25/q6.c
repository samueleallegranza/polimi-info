//      [!] NOT WORKING SOLUTION
#include <stdio.h>
#define N_ELEM 96
#define DIM_NOME_ELEM 30
#define DIM_NOME_MOL 15
#define DIM_SYM 2

typedef struct _elem {
    int numAtomico;
    char nome[DIM_NOME_ELEM+1];
    char simbolo[DIM_SYM+1];
} elemChimico_t;

typedef struct _mol {
    elemChimico_t * atomi;
    struct _mol * next;
} molecola_t;

void visualizza_molecola(molecola_t *);

int main(int argc, char * argv[]) {
    elemChimico_t H1 = {.numAtomico = 1, .nome="Hydrogen", .simbolo="H"};
    elemChimico_t H2 = {.numAtomico = 1, .nome="Hydrogen", .simbolo="H"};
    elemChimico_t O1 = {.numAtomico = 8, .nome="Oxygen", .simbolo="O"};

    molecola_t m1 = {.atomi = &O1, .next = NULL};
    molecola_t m0 = {.atomi = &H2, .next = &m1};
    molecola_t mh = {.atomi = &H1, .next = &m0};

    visualizza_molecola(&mh);
    return 0;
}

void visualizza_molecola(molecola_t * h) {
    molecola_t * p;
    int prevnum, currnum, accum;

    printf("hi");
    if(h != NULL) {
        p=h;
        prevnum = (p->atomi)->numAtomico;
        accum = 1;
        p = p->next;
        while(p != NULL) {
            currnum = (p->atomi)->numAtomico;
            if(currnum != prevnum) {
                prevnum = currnum;
                accum = 1;
                printf("%s_%d ", (p->atomi)->simbolo, accum);
            } else {
                accum++;
            }
            p = p->next;
        }
        printf("%s_%d ", (p->atomi)->simbolo, accum);
    } else {
        printf("Molecola vuota.\n");
    }

}
