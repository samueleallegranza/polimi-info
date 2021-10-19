#include <stdio.h>

int main(int argc, char * argv[])
{
	int min, max;
	int val, cont, tot;
	float avg;

    scanf("%d", &val);
    cont = 0;           // Parto da 0 (e non da 1)
    min = val;
    max = val;
    tot = 0;            // Inizializzo 'tot' a zero essendo sommatoria 
    while(val != 20) {
        if(val < min) {
            min = val;
        } else if (val > max) {
            max = val;
        }
        tot += val;
        cont++;
        scanf("%d", &val);
    }

	avg = (float) tot / cont;       // Aggiungo la specifica per il casting
	printf("%d %d %f\n", min, max, avg);

	return 0;
}