#include <stdio.h>

typedef void (*MathFunc)(int mat[][3], int);
typedef void (*PrintFunc)(void*);

void to_identity(int mat[][3], int rows)
{
    int* current_ptr = *mat;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                *current_ptr = 1;
            } else
            {
                *current_ptr = 0;
            }
            current_ptr++;
        }
    }
}

void first_matrix_print(int arr[][3], int rows) // Helper function, para los primeros 4 ejercicios
{
    int* current_ptr = *arr;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", *current_ptr);
            current_ptr++;
        }
        printf("\n");
    }
}

void print_mat(void* mat[][3], int rows, PrintFunc func)
{
    int* current_ptr = (int*)mat;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            func((void*)current_ptr);
            current_ptr++;
        }
        printf("\n");
    }
}

void print_int(void *value)
{
    printf("%d ", *(int*)value);
}

int main()
{
    printf("=== Ejercicio 1 ===\n");
    int mat1[][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {2,4,6}};
    to_identity(mat1, 4);
    first_matrix_print(mat1, 4);
    printf("=== Ejercicio 2 ===\n");
    MathFunc mf1 = to_identity;
    int mat_prueba[][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {2,4,6}};
    mf1(mat_prueba, 4);
    first_matrix_print(mat_prueba, 4); // Verificando que funciona, la declaración de solo 1 línea está arriba
    printf("=== Ejercicio 3 ===\n");
    int arr[6] = {0,1,2,3,4,5};
    int (*mat2)[3] = (int (*)[3])arr;
    first_matrix_print(mat2, 2); // Verificando
    printf("=== Ejercicio 4 ===\n");
    int x = 10;
    print_int(&x); printf("\n");
    printf("=== Ejercicio 5 ===\n");
    PrintFunc pf1 = print_int;
    print_mat((void*)mat_prueba, 4, pf1);

    return 0;
}