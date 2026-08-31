#include <stdio.h>

#define R 3
#define C 3

void printAll(char* words[10], int n)
{
    char** ap = words;
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", *ap);
        ap++;
    }
}

void addOne(int** ptr_arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        **(ptr_arr + i) += 1;
    }
}

void addTwo(int** ptr_arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        ptr_arr[i][0] += 2;
    }
}

int max_mat(int mat[R][C])
{
    int res = **mat;
    int* ptr = *mat;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (*ptr > res)
            {
                res = *ptr;
            }
            ptr++;
        }
    }
    return res;
}

void toLowerCase(char* words[], int n)
{
    char** word_ptr = words;
    for (int i = 0; i < n; i++)
    {
        char* char_ptr = *word_ptr;
        while (*char_ptr != '\0')
        {
            if (*char_ptr >= 65 && *char_ptr <= 90)
            {
                *char_ptr += 32;
            }
            char_ptr++;
        }
    }
}

int main()
{
    char* words[10] = {"Hola", "Mundo", "char", "int", "float"};
    printAll(words, 5);

    printf("=== Arreglos de Apuntadores ===\n\n");

    int a = 1, b = 2, c = 3;
    int* ptr_array[4] = {&a, &b, &c};
    // Asignando valor de 5 a la variable c
    *ptr_array[2] = 5;
    **(ptr_array + 2) = 7; // Ahora va a ser 7, notación de apuntadores
    ptr_array[2][0] = 10; // Ahora va a ser 10, con pura notación de arreglos
    printf("%d\n", c);

    printf("=== Ejercicio 2 ===\n\n");
    addOne(ptr_array, 3);
    printf("%d %d %d", a, b, c);
    printf("=== Ejercicio 3 ===\n\n");
    addTwo(ptr_array, 3);
    printf("%d %d %d\n", a, b, c);
    printf("=== Ejercicio 4 ===\n");
    int mat[R][C] = { {1,2,3}, {-1,-2,0}, {2,4,-3}};
    printf("%d\n", max_mat(mat));
    printf("=== Ejercicio 5 ===\n\n");
    char* palabras[10] = {"HOLA", "ADIOS", "Cruel5", "buENo"};
    toLowerCase(palabras, 4);


    return 0;
}
