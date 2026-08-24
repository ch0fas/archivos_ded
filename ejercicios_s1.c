// Variables y Apuntadores
// Aritmética de Apuntadores

#include <math.h>
#include <stdio.h>

typedef struct
{
    float v1;
    float v2;
} Vec2;

// custom len
int my_len(char* arr)
{
    int res = 0;
    while (arr[res] != '\0')
    {
        res++;
    }

    /* Otras formas de hacer el while loop
     * while (*(string + res) != '\0') { res++; }
     */
    return res;
}

int has_a(char* string)
{
    while (*string != 'a' && *string != 'A')
    {
        string++;
        if (*string == '\0') return 0;
    }
    return 1;
}

void swap(int *a, int *b)
{
    int placeholder = *b;
    *b = *a;
    *a = placeholder;
}

void toUnit(Vec2 *v)
{
    float norm = sqrt((pow(v->v1, 2) + pow(v->v2, 2)));
    v->v1 /= norm;
    v->v2 /= norm;
}

int main()
{
    // a)
    double r1 = -7.528;
    double* p1 = &r1;

    // b)
    printf("Valor de p1: %p.\nDirección de p1: %p\n", p1, &p1);

    // c)
    *p1 /= 2;
    printf("%f\n", r1);

    // d)
    short arr[100];

    // e)
    short* p3 = arr + 2;
    *p3 = 8;
    printf("%d\n", arr[2]);

    char test[100] = "Test";
    char bar[100] = "bar";
    printf("%d\n", my_len(test));
    printf("%d\n", has_a(test));
    printf("%d\n", has_a(bar));

    int a = 35;
    int b = 40;
    swap(&a,&b);
    printf("%d, %d\n", a, b);

    Vec2 v = {3.0, 4.0};
    toUnit(&v);
    printf("%.1f, %.1f", v.v1, v.v2);
}
