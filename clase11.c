// Devolviendo arreglos
// Para lograr esto en C, es necesario incluir el arreglo de resultado como argumento. Este sería creado con memoria dinámica

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int* sumar(int a1[], int a2[], int N)
{
    int* a3 = (int*) malloc(N * sizeof(int)); // Creando el arreglo retornado con memoria dinámica
    for (int i = 0; i < N; i++)
    {
        a3[i] = a1[i] + a2[i];
    } // esto también puede hacerse con notación de apuntadores, evidentemente

    return a3; // No se usa free() porque no es un malloc temporal
}

float* normalize(float* vector, int N)
{
    float* res = (float*) malloc(N * sizeof(float));
    float* rp = res;
    float sumatoria = 0;
    float* ptr = vector;
    for (int i = 0; i < N; i++)
    {
        sumatoria += (*ptr) * (*ptr);
        ptr++;
    }

    double mag = sqrt(sumatoria);

    ptr = vector;
    for (int i = 0; i < N; i++)
    {
        *rp = *ptr / mag;
        rp++;
        ptr++;
    }

    return res;
}

char* toLower(char* string)
{
    char* res = (char*) malloc(strlen(string));
    char* rp = res;
    char* ptr = string;
    while (*ptr != '\0')
    {
        *rp = *ptr + 32;
        rp++;
        ptr++;
    }

    return res;
}

int main()
{
    int a1[] = {1,2,3,4,5};
    int a2[] = {6,7,8,9,10};
    int* a3 = sumar(a1, a2, 5);
    printf("%d %d %d %d %d\n", a3[0], a3[1], a3[2], a3[3], a3[4]);
    printf("== Normalize ==\n");
    float v1[] = {3.0, 4.0};
    float* nv1 = normalize(v1, 2);
    printf("%2f %2f\n", nv1[0], nv1[1]);
    printf("=== toLowerCase ===\n");
    char* word = "HELLO";
    char* lower = toLower(word);
    printf("%s\n", lower);

    free(a3); // Técnicamente redundante, pero es buena práctica
    free(nv1);
    free(lower);
}
