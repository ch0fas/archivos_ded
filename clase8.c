// Memoria dinámica

#include <iso646.h>

int main()
{
    int x = 10;
    x++;
    const int y = 20;
    // y++; No funciona porque es una constante

    int* const px = &x; // Relación de pareja
    int z = 30;
    (*px)++; // Pero se pueden seguir haciendo operaciones con el apuntador, solo no puede apuntar a nadie más.
    // px = &z; Ahora, px está "casado" con x, no se le puede asignar otra dirección de memoria

    const int* py = &y; // Pointer to constant, relación de amistad
    // (*py)++; No se puede modifica rle valor apuntador
    py = &z; // Pero si puede apuntar a alguien más.

    const int* const pz = &z; // Constant pointer to constant, mal matrimonio
    // (*pz)++; No se puede modificar su valor
    // pz = &x; Ni puede apuntar a alguien más
    return 0;
}
