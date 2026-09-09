#include <stdio.h>
#include <stdlib.h>

int g = 30; // Datos o BSS

void function()
{
    int y = 20; // Stack
    y++;
    printf("%d %p\n", y, &y);

    static int z = 40; // Static es una variable global, solo accesible en un método
    z++; // z va a estar más cerca de g en memoria que y
    printf("%d %p\n", z, &z);
}

int main()
{
    int x = 10; // Stack
    printf("&x = %p\n", &x);
    printf("&p = %p\n", &g);
    function();
    function(); // aunque son dos llamadas distintas, como es una repetición muy sencilla, va a reutilizar la misma dirección de memoria a ambas "y"


    int* arr;
    int N = 30;

    // Solicitando la cantidad de memoria
    arr = malloc(N * sizeof(int)); // estoy reservando espacio en memoria para que arr pueda almacenar 30 integers
    arr[0] = 0;
    arr[N-1] = 100;

    free(arr); // Libera esa memoria
    printf("%d\n", arr[29]); // Siguen almacenando lo mismo, pero eso que almacenan ya no representa direcciones con datos
    return 0;
}
