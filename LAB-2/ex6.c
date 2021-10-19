#include <stdio.h>
#define MAX 30

int main(int argc, char * argv[]) {
  char str[MAX+1], norep[MAX+1];
  int i, j, count;
  int found;

  /* Input with spaces*/
  gets(str);

  for(i=0, count=0; str[i]!='\0'; i++) {
    if(str[i] != ' ') {
      for(j=0, found = 0; j<count && !found; j++) {
        if(str[i] == norep[j])
          found = 1;
      }
    }
    if(!found || (str[i] == ' ')) {
      norep[count] = str[i];
      count++;
    }
  }
  norep[count] = '\0';

  printf("%s\n", norep);

  return 0;
}
