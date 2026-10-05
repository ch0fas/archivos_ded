#include <stdio.h>
#include <stdlib.h>
#include "data_structures/Stack.h"

typedef struct strDate
{
    unsigned int day, month, year;
    // Date self; no funciona porque Date aún no está definido
    // struct strDate self; no funciona, tipo incompleto
    struct strDate* self; // Tiene que ser apuntador para que no tenga problema el compilador
    struct strDate* next;
    // struct strDate *self, *next; si quisiéramos declarar ambas en la misma línea
} Date;

void next_month(Date* date)
{
    if (date->month == 12)
    {
        date->month = 1;
        date->year++;
    }
    else { date->month++; }
}

void print_dates(Date* date)
{
    if (date != NULL)
    {
        printf("Foo%02d/%02d/%02d\n", date->day, date->month, date->year%100);
        print_dates(date->next);
        printf("%02d/%02d/%02d\n", date->day, date->month, date->year%100);
    }
}

int main()
{
    Date d1 = {5, 10, 2026};
    d1.self = &d1;
    // printf("%02d/%d/%d\n", d1.day, d1.month, d1.year);

    Date d2 = {6, 12, 2026};
    d2.self = &d2;
    // printf("%02d/%2d/%d\n", d2.day, d2.month, d2.year);

    next_month(d1.self);
    // printf("%02d/%d/%d\n", d1.day, d1.month, d1.year);
    next_month(d2.self);
    // printf("%02d/%02d/%d\n", d2.day, d2.month, d2.year);

    // d2.self = &d1;Esto tmb se puede, aunque por ahora no es demasiado útil

    Date d3 = {15, 9, 2020};
    // Construyendo una pequeña lista: d0 -> d1 -> d2 -> d3 -> o
    Date* d0 = (Date*) malloc(sizeof(struct strDate));
    d0->day = 20;
    d0->month = 11;
    d0->year = 2021;
    d0->self = d0;
    d0->next = &d1;

    d1.next = &d2;
    d2.next = &d3;
    d3.next = NULL;

    print_dates(d0);

    Stack st1 = stack_create();
    printf("%p\n", st1);

    return 0;
}
