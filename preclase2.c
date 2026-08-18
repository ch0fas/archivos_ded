#include <stdio.h>

int main()
{
    float f = 3.14;
    float* pf = &f;
    printf("%p\n", pf);
    pf ++;
    printf("%p\n", pf);
    pf += 3;
    printf("%p\n", pf);
    pf -= 2;
    printf("%p\n", pf);
    pf --;
    printf("%p\n\n\n", pf);

    int arr[5] = {};
    printf("%p\n", arr); // Imprime la dirección del primer elemento en el arreglo

    *arr = 5;
    printf("%d\n", arr[0]);

    int* parr = arr;
    printf("%d\n", parr[0]); // Imprime lo mismo que arriba
    // arr++; Esto genera error
    parr++; // Esto no
    *parr = 6;
    printf("%d\n", parr[0]); // Ahora, el primer valor de parr es 6
    printf("%d\n", arr[1]);

    return 0;
}
