/*
    Samuele Allegranza @ Polimi
        Fondamenti di informatica - Esercitazione

    > Esercizio:
    Scrivere un programma che acquisisca in ingresso una
    stringa di esattamente 9 caratteri composta esclusivamente
    da 'x' e 'o'; si assuma che l'utente inserisca 
    correttamente la stringa.
    La stringa rappresenta una particolare configurazione del
    gioco del tris, dove i primi 3 caratteri corrispondono
    alla prima riga, i secondi 3 alla seconda riga e gli
    ultimi 3 all'ultima riga.
    Si converta la stringa ricevuta in ingresso in un modello
    del dato che rappresenti lo schema di gioco del tris,
    ovvero un array bidimensionale quadrato di dimensione 3,
    e si determini quindi se la configurazione attuale e' una
    configurazione vincente, ovvero se c'e un tris.
    NOTA: Si assuma che la stringa passata in ingresso sia una
    configurazione valida per il gioco del tris (in relazione
    al numero di simboli per tipo).
    
*/
#include <stdio.h>
#define ROWS 3
#define COLS 3
#define INPUT_LEN 9

int main(void) {

    char table[ROWS][COLS];
    char input[INPUT_LEN+1];
    int i, j;
    int tris, possible, first;

    scanf("%s", input);
    
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            table[i][j] = input[i*ROWS + j];
        }
    }

    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%c", table[i][j]);
        }
        printf("\n");
    }


    tris = 0;

    // Check rows
    for(i=0; i<ROWS && !tris; i++) {
        first = table[i][0];
        possible = 1;
        for(j=1; j<COLS && possible; j++)
            if(first != table[i][j])
                possible = 0;
        tris = possible;
    }

    // Check columns
    for(j=0; j<COLS && !tris; j++) {
        first = table[0][j];
        possible = 1;
        for(i=0; i<ROWS && possible; i++)
            if(first != table[i][j])
                possible = 0;
        tris = possible;
    }

    //Check diagonals
    //[Missing code here]

    printf("%d\n", tris);

    return 0;
}