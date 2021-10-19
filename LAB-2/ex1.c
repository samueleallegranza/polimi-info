#include <stdio.h>
#define MAX 100

int main(int argc, char * argv[]) {
  int values[MAX];
  int target, found;
  int input, qt;
  int i,j;

  /* List of values */
  qt=0;
  scanf("%d", &input);
  /* Assuming the user inserts at most 100(+1) values*/
  while(input>0) {
    values[qt] = input;
    qt++;
    scanf("%d", &input);
  }

  /* Taget value */
  scanf("%d", &target);

  found = 0;
  for(i=0; i<(qt-1) && !found; i++)
    for(j=(i+1); j<qt && !found; j++)
      if(values[i] + values[j] == target)
        found = 1;

  printf("%d\n", found);

  return 0;
}
