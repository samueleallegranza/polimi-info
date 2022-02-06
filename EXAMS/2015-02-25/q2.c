#include <stdio.h>

int main(int argc, char * argv[]) {
    float real, max, min, avg, sum;
    int count;

    scanf("%f", &real);
    if(real != 0) {
        max = real; min = real;
        sum = real; count = 1;

        scanf("%f", &real);
        while(real != 0) {
            count++;
            sum += real;
            if(real > max) {max = real;}
            if(real < min) {min = real;}
            scanf("%f", &real);
        }
        avg = sum/count;

        printf("Max: %.2f\nMin: %.2f\nAvg: %.2f\n", max, min, avg);
    } else {
        printf("Not enough data.\n");
    }

    return 0;
}
