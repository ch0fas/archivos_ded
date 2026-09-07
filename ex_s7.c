#include <stdio.h>

typedef struct
{
    int day, month, year;
} Date;

int compare_float(void* f1, void* f2)
{
    if (*f1 < *f2) return -1;
    if (*f1 > *f2) return 1;
    else return 0;
}

int compare_int(int* i1, int* i2)
{
    return *i1 - *i2;
}

int compare_date(Date* d1, Date* d2)
{
    int f1 = (d1->year * 365) + ((d1->month - 1) * 30) + d1->day;
    int f2 = (d2->year * 365) + ((d2->month - 1) * 30) + d2->day;

    return f1 - f2;
}

int main()
{
    float x = 3.4, y = 4.8, z = 4.8;
    int a = 3, b = 4, c = 3;
    Date d1 = {27, 8, 2020}, d2 = {15, 12, 2008}, d3 = {27, 8, 2020};
    printf("%d\n", compare_float(&x, &y));
    printf("%d\n", compare_float(&y, &x));
    printf("%d\n", compare_float(&y, &z));
    printf("%d\n", compare_int(&a, &b));
    printf("%d\n", compare_int(&b, &a));
    printf("%d\n", compare_int(&a, &c));
    printf("%d %d %d\n", compare_date(&d1, &d2), compare_date(&d2, &d1), compare_date(&d1, &d3));
    return 0;
}
