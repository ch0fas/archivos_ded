// Tarea Ejercicio 3: Estructuras
// Sofia Maldonado

// Preguntale al usuario cuantas estaturas se van a capturar
// Pide cada estatura y guardala en un arreglo donde quepan todas]
// Pregunta cuantos más quiere
// Pide cada estatura adicional y guárdala en el mismo arreglo
// Al final, imprime todas las estaturas, la mayor, la menor, y el promedio

#include <stdio.h>
#include <stdlib.h>

void initArray_v2(int** arr, int N) // Copiando la función que hicimos hoy en clase
{
    *arr = (int*)calloc(N, sizeof(int*));
}

void about_arr(int* arr, int N)
{
    int biggest = -2147483648;
    int smallest = 2147483647;
    double avg = 0;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] > biggest)
        {
            biggest = arr[i];
        }
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
        avg += arr[i];
    }

    printf("Estatura mayor: %d\nEstatura menor: %d\nPromedio de estaturas: %2f", biggest, smallest, avg/N);
}

int main()
{
    int* heights_arr = NULL;
    int first_n, second_n;

    printf("Cuántas estaturas vas a captar? ");
    scanf("%d", &first_n);
    initArray_v2(&heights_arr, first_n);

    for (int i = 0; i < first_n; i++)
    {
        int temp_h;
        printf("Ingresa la estatura %d: ", i+1);
        scanf("%d", &temp_h);
        heights_arr[i] = temp_h;
    }
    printf("Cuántas más vas a captar? ");
    scanf("%d", &second_n);
    heights_arr = (int*) realloc(heights_arr, (first_n + second_n) * sizeof(int));
    for (int i = first_n; i < (first_n + second_n); i++)
    {
        int temp_h;
        printf("Ingresa la nueva estatura %d: ", i+1);
        scanf("%d", &temp_h);
        heights_arr[i] = temp_h;
    }

    printf("=== Estaturas ===\n");
    for (int i = 0; i < (first_n + second_n); i++)
    {
        printf("%dm\n", heights_arr[i]);
    }

    about_arr(heights_arr, (first_n + second_n));


    return 0;
}