/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Si scriva un sottoprogramma che ricevuti in ingresso 3
    valori interi positivi corrispondenti ai valori di
    ore, minuti e secondi ritorni al chiamante il numero
    totale di millisecondi trascorsi da inizio giornata
    corrispondente all'orario specificato.
*/
#include <stdio.h>
#define SEC_IN_MIN 60
#define SEC_IN_HOUR 3600
#define MS_IN_SEC 1000

int to_ms(int, int, int);

int main(int argc, char * argv[]) {
  printf("%d\n", to_ms(12, 0, 0));
  return 0;
}

int to_ms(int h, int m, int s) {
  return ((s)+(m*SEC_IN_MIN)+(h*SEC_IN_HOUR))*MS_IN_SEC;
}
