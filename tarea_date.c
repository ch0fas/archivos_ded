#include <stdio.h>
#include <string.h>

typedef struct
{
    int day, month, year;
} Date;

char* months[12] = {"Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};

typedef void (*PrintFunc)(Date*);

void printShortDate(Date *d)
{
    if (d->month < 10) printf("%d/0%d/%02d\n", d->day, d->month, (d->year % 100));
    else printf("%d/%d/%02d\n", d->day, d->month, d->year % 100);
}

void printMediumDate(Date *d)
{
    printf("%d-%s-%d\n", d->day, months[(d->month)-1], d->year);
}

void printDates(Date* dates[], int n, PrintFunc f)
{
    for (int i = 0; i < n; i++)
    {
        f(dates[i]);
    }
}

int main()
{
    Date d = {17, 4, 2005};
    Date d2 = {18, 10, 2005};
    Date d3 = {15, 10, 2005};
    Date* dates[3] = {&d, &d2, &d3};
    Date* pd = &d;
    printShortDate(pd);
    void (*fp1)(Date*) = printShortDate;
    void (*fp2)(Date*) = printMediumDate;
    printDates(dates, 3, fp1);
    printDates(dates, 3, fp2);
    return 0;
}
