#include <stdio.h>
#define MAX 20

int main(int argc, char * argv[]) {
  int values[MAX];
  int qt;
  int i, j, input;

  /* Quantity of values */
  do {
    scanf("%d", &qt);
  } while(qt>20 && qt<=0);

  scanf("%d", &values[0]);

  for(i=1, j=1; i<qt; i++) {
    scanf("%d", &input);
    if(input>values[j-1]) {
      values[j] = input;
      j++;
    }
  }

  printf("%d\n", j);
  for(i=0; i<j; i++) {
    printf("%4d", values[i]);
  }
  printf("\n");


  return 0;
}
