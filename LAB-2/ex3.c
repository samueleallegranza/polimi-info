#include <stdio.h>
#define DIM 20

int main(int argc, char * argv[]) {
  int seq1[DIM];
  int seq2[DIM];
  int i, j, pivot, min;
  int tmp;
  int min1, min2, prev;

  for(i=0; i<DIM; i++) {
    scanf("%d", &seq1[i]);
  }
  for(i=0; i<DIM; i++) {
    scanf("%d", &seq2[i]);
  }

  for(pivot=0; pivot<(DIM-1); pivot++) {
    min = pivot;
    for(i=(pivot+1); i<DIM; i++) {
      if(seq1[i] < seq1[min])
        min = i;
    }
    tmp = seq1[pivot];
    seq1[pivot] = seq1[min];
    seq1[min] = tmp;
  }

  for(pivot=0; pivot<(DIM-1); pivot++) {
    min = pivot;
    for(i=(pivot+1); i<DIM; i++) {
      if(seq2[i] < seq2[min])
        min = i;
    }
    tmp = seq2[pivot];
    seq2[pivot] = seq2[min];
    seq2[min] = tmp;
  }


  i=0; j=0;
  min1 = seq1[i];
  min2 = seq2[j];
  if(min1 < min2) {
    printf("%d", min1);
    prev = min1;
    i++;
  } else {
    printf("%d", min2);
    prev = min2;
    j++;
  }

  while(i<DIM || j<DIM) {
    if(seq1[i] < seq2[j]) {
      if(prev < seq1[i]) {
        printf("%3d", seq1[i]);
        prev = seq1[i];
      }
      i++;
    } else {
      if(prev < seq1[j]) {
        printf("%3d", seq1[j]);
        prev = seq1[j];
      }
      j++;
    }
  }

  printf("\n");

  return 0;
}
