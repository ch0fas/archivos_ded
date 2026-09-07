// Apuntadores void
//
// Sirve para que un método pueda aceptar todo tipo de datos

#include <stdio.h>

void sort_objects(void* arr[], int n); // Aquí, void es un comodín, es un apuntador a cualquier cosa

int main()
{
    float a = 8.5; int b = 8; char c[] = "Hola";
    void* pointer = &a; // Como pointer es un apuntador comodín, puede apuntar a un float y a un int (sounds dangerous pero qué se yo)
    printf("%p\n", pointer);
    pointer = &b; printf("%p\n", pointer);
    pointer = &c; printf("%p\n", pointer);
    printf("%s\n", pointer); // Hay un warning pero si imprime "Hola", dependiendo del formato lo imprime como mejor puede
    printf("%f\n", pointer);
    printf("%f\n", pointer);
    pointer++; // Esta operación con un void* ptr suma una dirección de memoria
    // *pointer *= 2; Esto no se puede, ya que no se puede saber con certeza si esta operación sería válida con lo que sea que pointer esté apuntando
    float* pf = (float*) pointer;
    *pf *= 2; // Aquí, la operación si es válida, porque se sabe que el apuntador pf siempre va a apuntar a un valor numérico al que si se le puede hacer esta operación.

    // Serán útiles para contenedores genéricos


    return 0;
}
