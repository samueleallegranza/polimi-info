#include <stdio.h>
#define MAX 30

int main(int argc, char * argv[]) {

  char str[MAX+1];
  int maxlen, len;
  int i, j, k;
  int rep;

  scanf("%s", str);

  maxlen = 0;
  for(i=0; str[i]!='\0'; i++){
    len=1;
    for(j=(i+1), rep=0; (str[j]!=str[i]) && (str[j]!='\0') && !rep; j++, len++) {
      for(k=(j-1); k>=i && !rep; k--) {
        if(str[k] == str[j])
          rep = 1;
      }
      if(rep)
        len--;
    }

    if(len>maxlen) {
      maxlen = len;
    }
  }

  printf("%d\n", maxlen);

  return 0;
}
