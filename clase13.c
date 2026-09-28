// Arreglos por referencia

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función que construye el arreglo

void initArray_v1(int* arr, int N)
{
    arr = (int*) calloc(N, sizeof(int)); // Para que sea un arreglo de ceros
    printf("Después de calloc: %p\n", arr);
}

void initArray_v2(int** arr, int N)
{
    *arr = (int*)calloc(N, sizeof(int*));
}

// Ejercicio 1
// Crear un método initString que construya una cadena de texto compacta cuyo ontenido sea igual al de un arreglo de caracteres recibido
// Compacto es que solo debe eocuar el espacio de memoria necesario

void initString(char** word, char* source)
{
    *word = (char*)malloc(( 1 + sizeof(source)) * sizeof(char));

    strcpy(*word, source);
}

// Ejercicio 2
// Crea una struct Socket con un string de 4 char, entero de 16 bits sin signo
// Función initSockets que reciba un arreglo de apuntadores a sockets y un entero N
// Crear un arreglo que pueda almacenar N sockets y crea sockets default con valor 127.0.0.1:80

typedef struct
{
    unsigned char address[4];
    unsigned short port;
} Socket;

void initSockets(Socket*** sockets, int N)
{
    *sockets = (Socket**) malloc(N * sizeof(Socket*));
    for (int i = 0; i < N; i++)
    {
        (*sockets)[i] = (Socket*)malloc(sizeof(Socket));
        (*sockets)[i]->address[0] = 127;
        (*sockets)[i]->address[1] = 0;
        (*sockets)[i]->address[2] = 0;
        (*sockets)[i]->address[3] = 1;
        (*sockets)[i]->port = 80;
    }
}

int main()
{
    int* array = NULL;
    printf("Creando arreglo: %p\n", array);
    initArray_v1(array, 10); // Helper function para construir arreglos de int con cierto tamaño

    if (!array)
    {
        printf("No se pudo crear el arreglo\n");
    }

    int* arr_2 = NULL;
    initArray_v2(&arr_2, 10); // Pasamos la dirección del apuntador a inicializar

    if (arr_2)
    {
        printf("Arreglo arr_2 inicializado correctamente!\n"); // Ahora si se inicializa
        printf("Primer elemento: %d\n", arr_2[0]);
    }

    // Ejercicio 1
    printf("=== Ejercicio 1 ===\n");
    char* target = NULL;
    char* test_string = "HolaMundo";
    initString(&target, test_string);
    printf("Ejercicio 1 -> ");
    puts(target);

    free(target);

    // Ejercicio 2
    printf("=== Ejercicio 2 ===\n");
    Socket s1 = {{1,2,3,4}, 80};
    Socket** sockets;
    initSockets(&sockets, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d.%d.%d.%d:%d\n", sockets[i]->address[0], sockets[i]->address[1], sockets[i]->address[2], sockets[i]->address[3], sockets[i]->port);
    }

    // Crecimiento de arreglos
    // Empezamos con size = 10, sube a size = 14

    int N = 10; // El tamaño original
    int* arr_c = (int*)malloc(N*sizeof(int));
    for (int i = 0; i < N; i++) { arr_c[i] = i; }
    int M = 4; // Lo que va a aumentar
    arr_c = (int*) realloc(arr_c, (N + M) * sizeof(int));
    // Verificando no haber perdido nada
    printf("Verifying\n");
    for (int i = 0; i < N; i++) {printf("%d\n", arr_c[i]);}
    // agregando nuevos valores
    for (int i = N; i < N+M; i++) { arr_c[i] = i; }
    // Verificando todos los valores
    printf("\nVerifying again\n");
    for (int i = 0; i < N+M; i++) { printf("%d\n", arr_c[i]); }

    return 0;
}
