#include <stdio.h>

typedef struct
{
    int day, month, year;
} Date;

int main()
{
    int x = 1;
    double y = 3.1416;
    Date z = {17, 4, 2005};
    char w = 'a';
    void* array[6] = {&x, &y, &z};
    array[3] = &w;
    double* d = array[1];
    printf("%f\n", *d);

    int* i = array[0];
    (*i)++;
    printf("%d\n", x);

    char s[] = "Hola";
    array[4] = s;
    printf("%s\n", array[4]);
    return 0;
}