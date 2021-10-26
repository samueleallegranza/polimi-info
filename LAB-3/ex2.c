#include <stdio.h>
#define PEOPLE 100

typedef struct date_s {
    int g;
    int m;
    int a;
} date_t;

void collect_data(date_t [], int);
int same_date(date_t [], int, date_t);
int same_day(date_t [], int, date_t);

int main(int argc, char * argv []) {
    date_t birthdays[PEOPLE];
    int same_date_n, same_day_n;
    date_t target;

    collect_data(birthdays, PEOPLE);

    scanf("%d%d%d", &target.g, &target.m, &target.a);

    same_date_n = same_date(birthdays, PEOPLE, target);
    same_day_n = same_day(birthdays, PEOPLE, target);

    printf("%d %d\n", same_date_n, same_day_n);

    return 0;
}

void collect_data(date_t arr[], int len) {
    int i;
    for(i=0; i<len; i++) {
        scanf("%d%d%d", &arr[i].g, &arr[i].m, &arr[i].a);
    }
}

int same_date(date_t arr[], int len, date_t target) {
    int i, count;
    for(i=0, count=0; i<len; i++) {
        if(
            arr[i].g == target.g &&
            arr[i].m == target.m &&
            arr[i].a == target.a
        )
            count++;
    }
    return count;
}

int same_day(date_t arr[], int len, date_t target) {
    int i, count;
    for(i=0, count=0; i<len; i++) {
        if(
            arr[i].g == target.g &&
            arr[i].m == target.m
        )
            count++;
    }
    return count;
}
