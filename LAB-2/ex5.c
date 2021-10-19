#include <stdio.h>
#define MAX_WORDS 20
#define MAX_CHARS 25
#define FRAME '*'

int main(int argc, char * argv[]) {

  int num_words;
  char words[MAX_WORDS+1][MAX_CHARS+1];
  int maxlen, i, j, ended;

  do {
    scanf("%d", &num_words);
  } while(num_words>MAX_WORDS && num_words<0);

  for(i=0; i<num_words; i++) {
    scanf("%s", &words[i][0]);
  }

  maxlen = 0;
  for(i=1; i<num_words; i++) {
    for(j=0; words[i][j] != '\0'; j++);

    if(j>maxlen)
      maxlen=j;
  }

  /* Print upper frame */
  for(i=0; i<(maxlen+2); i++) {
    printf("%c", FRAME);
  }
  printf("\n");

  /* Print internal */
  for(i=0; i<num_words; i++) {
    printf("%c", FRAME);
    for(j=0, ended=0; j<maxlen; j++) {
      if(words[i][j] == '\0')
        ended = 1;
      if(ended)
        printf(" ");
      else
        printf("%c", words[i][j]);
    }
    printf("%c\n", FRAME);
  }

  /* Print lower frame */
  for(i=0; i<(maxlen+2); i++) {
    printf("%c", FRAME);
  }
  printf("\n");



  return 0;
}
