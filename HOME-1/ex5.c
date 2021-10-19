#include <stdio.h>
#define MAX 50

typedef struct _operator {
    float energy_price;
    float gas_price;
    char name[MAX];
} operator;


int main(void) {
    operator op1, op2;
    float energy_usage, gas_usage;
    float energy_total1, energy_total2;
    float gas_total1, gas_total2;

    scanf("%f%f%s", &op1.energy_price, &op1.gas_price, op1.name);
    scanf("%f%f%s", &op2.energy_price, &op2.gas_price, op2.name);
    scanf("%f%f", &energy_usage, &gas_usage);

    energy_total1 = op1.energy_price * energy_usage;
    energy_total2 = op2.energy_price * energy_usage;

    gas_total1 = op1.gas_price * gas_usage;
    gas_total2 = op2.gas_price * gas_usage;

    if((energy_total1+gas_total1) < (energy_total2+gas_total2)) {
        printf("%s\n", op1.name);
    } else {
        printf("%s\n", op2.name);
    }

    return 0;
}
