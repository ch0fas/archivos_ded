// Aritmética de Apuntadores
// Pase Por Referencia

#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

typedef struct // unsigned porque sabemos que esos valores no pueden ser negativos
{
    unsigned int semestre;
    char nombre[30];
    char carrera[30];
    double promedio;
    unsigned short edad;
} Alumno;

void duplicate(int *x)
{
    *x *= 2;
}

int main()
{
    Alumno a1 = {7, "Sofia Maldonado García", "Ciencia de Datos", 9.3, 21};
    Alumno a2;
    a2.semestre = 3;
    strcpy(a2.nombre, "Erwin Carreon");
    strcpy(a2.carrera, "Sistemas Computacionales");
    a2.promedio = 9.0;
    a2.edad = 19;

    Alumno* pa1 = &a1;

    (*pa1).edad = 47; // Cambiar valores en la estructura con el apuntador
    pa1->promedio = 6.7; // También se puede hacer así
    printf("%d, %.2f\n", a1.edad, a1.promedio);

    short s1 = 15, s2 = 20;
    printf("(%d, %d)\n", s1, s2);
    // Creando un pointer
    short *ps1 = &s1;
    printf("ps1 = %p\n", ps1);
    printf("%p\n", &s2);
    printf("%p\n", &ps1);
    printf("%ld\n", sizeof ps1);

    ps1++;
    printf("ps1 = %p\n", ps1);
    ps1 -= 3;
    printf("ps1 = %p\n", ps1);
    printf("%d\n", *ps1);

    short arr[] = {1,2,3,4,5};
    printf("array= %p\n", arr);
    short* parr = arr;
    printf("%d\n", *parr);
    parr++;
    printf("%d\n", *parr);
    parr+= 2;
    *parr = 30;
    parr[-1] = 2000;
    printf("%d\n", *parr);
    printf("%d\n", *(arr+2));
    *(arr + 4) = 10;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }

    // pase por referencia
    int a = 100;
    printf("%p\n", &a);
    duplicate(&a);
    printf("%d\n", a);
    return 0;
}
