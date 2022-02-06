#include <stdio.h>
#define DIM 10

int main(int argc, char * argv[]) {
    int x, y, z;
    int v[DIM];
    int max, isfirst;

    for(x=0; x<DIM; x++)
        scanf("%d", &v[x]);

    isfirst = 1;
    for(x=0; x<DIM; x++) {
        for(y=(x+1); y<DIM; y++) {
            for(z=(y+1); z<DIM; z++) {
                if((v[x]*v[y]*v[z])>max || isfirst) {
                    max = (v[x]*v[y]*v[z]);
                    isfirst = 0;
                }
            }
        }
    }

    printf("Max: %d\n", max);

    return 0;
}
