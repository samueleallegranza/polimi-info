#include <stdio.h>

int containsSeq(int [], int, int, int);
int isRep(int [], int);

int main(int argc, char * argv[]) {
    int dim = 9;
    int arr[] = {3, 7, 1, 5, 4, 6, 2, 8, 9};
    int da, a;

    da = 1; a = 9;
    printf("%d\n", containsSeq(arr, dim, da, a));

    return 0;
}

int isRep(int arr[], int i) {
    int j;

    j = i-1;
    while(arr[i] != arr[j] && j>=0)
        j--;

    // If j>=0 it means that a repetition has been encountered at position j
    // The function checks if there are ANY of them
    return (j > -1);
}

int containsSeq(int arr[], int dim, int da, int a) {
    int i;
    int isok;

    for(i=0; i<dim; i++) {
        isok = 1;
        if(arr[i]>=da && arr[i]<=a) {
            isok = !isRep(arr, i);
        }
    }

    return isok;
}
