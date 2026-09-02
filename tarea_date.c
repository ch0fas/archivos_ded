#include <stdio.h>
#include <string.h>

typedef struct
{
    int day, month, year;
} Date;

char* months[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

void printShortDate(Date *d)
{
    if (d->month < 10) printf("%d/0%d/%02d\n", d->day, d->month, (d->year % 100));
    else printf("%d/%d/%02d\n", d->day, d->month, d->year % 100);
}

int main()
{
    Date d = {17, 4, 2005};
    Date* pd = &d;
    printShortDate(pd);
    return 0;
}
