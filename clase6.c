// Apuntadores a funciones (scary)
// Un ejemplo de uso es el manejo de eventos de usuario en GUIs o TUIs

#include <math.h>
#include <stdio.h>

typedef unsigned long long int64;
typedef struct
{
    int x, y, z;
} Vec3D;

typedef int (*Func3d)(int, int);

typedef float (*Func2d)(float);
typedef enum {False, True} Bool;

Bool isLinear(Func2d f)
{
    if (f(20000.0f) / f(10000.0f) >= 1.99f && f(20000.0f) / f(10000.0f) <= 2.01f)
    {
        return True;
    } else return False;

}

void saludar() { printf("Hola\n"); }
void despedirse() { printf("Adios\n"); }
void imprimirDoble(int x) { printf("%d\n", 2*x); }
void imprimirTriple(int x) { printf("%d\n", 3*x); }
int sumar(int a, int b) { return a + b; }
int restar(int a, int b) { return a - b; }
float func_one(float x) { return 4*x - 2; }
float func_two(float x) { return 3*x*x - 2*x + 4; }
float func_three(float x) { return 6*sqrtf(x) + 2; }


int main()
{
    saludar();
    despedirse();
    imprimirDoble(6);
    imprimirTriple(7);
    printf("%d\n", sumar(6, 7));
    printf("%d\n", restar(7, 6));

    // void (*fp1)();
    // void (*fp1)() = NULL;
    // fp1 = saludar;
    void (*fp1)() = saludar;
    fp1();
    printf("%p %p\n", fp1, saludar);

    fp1 = despedirse;
    fp1();
    printf("%p %p\n", fp1, despedirse);

    void (*fp2)(int) = imprimirDoble;
    fp2(6);
    printf("%p %p\n", fp2, imprimirTriple);
    fp2 = imprimirTriple;
    fp2(20);
    printf("%p %p\n", fp2, imprimirTriple);

    int (*fp3)(int, int) = sumar;
    printf("%d\n", fp3(6,7));
    printf("%p %p\n", fp3, sumar);
    fp3 = restar;
    printf("%d\n", fp3(7,6));
    printf("%p %p\n", fp3, restar);
    Func3d fp4 = sumar;
    Func3d func_arr[10]; // Hace más fácil tener arreglos de funciones
    Func2d fp5 = func_one;
    Func2d fp6 = func_two;
    Func2d fp7 = func_three;
    Func2d func_arr2[3] = {fp5, fp6, fp7};
    int n = sizeof func_arr2 / sizeof(Func2d);
    for (int i = 0; i < n; i++)
    {
        printf("Es lineal la func%d? %d\n", i+1, isLinear(func_arr2[i]));
    }

    return 0;
}
