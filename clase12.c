#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 100
#define C 50

typedef struct
{
    double price;
    int inventory;
    char name[30];
} Product;
void print_matrix(int** m, int r, int c)
{
    int* ptr = *m;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", *ptr);
            ptr++;
        }
        printf("\n");
    }
}

int** transpose_mat(int** m, int r, int c)
{
    int** res = (int**) malloc(c * sizeof(int*));
    for (int i = 0; i < c; i++)
    {
        res[i] = (int*) malloc(r * sizeof(int));
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            res[i][j] = m[j][i];
        }
    }

    return res;
}

void free_matrix(int** m, int r)
{
    for (int i = 0; i < r; i++)
    {
        free(m[i]);
    }

    free(m);
}

int main()
{
    // Matriz con memoria estática, donde las dimensiones deben ser conocidas desde antes por el compilador
    double mat1[R][C] = {};

    // Matriz con memoria dinámica
    // Paso 1 -> Crear arreglo de apuntadores a filas (primera dimension)
    double** mat2 = (double**) malloc(R * sizeof(double*));

    // Paso 2 -> Crear cada fila con C columnas
    for (int i = 0; i < R; i++)
    {
        mat2[i] = (double*) malloc(C * sizeof(double));
    }

    // Paso 3 -> Usando la matriz
    mat1[3][2] = 4.5;
    mat2[6][4] = 3.1416; // Ambas matrices se pueden modificar de la misma manera

    // Paso 4 -> Liberar la memoria, lo que hiciste al final se destruye primero
    for (int i = 0; i < R; i++)
    {
        free(mat2[i]);
    }

    free(mat2);

    printf("=== Ejercicios ===\n");
    int r, c;
    printf("Cuántas filas tendrá la matriz? ");
    scanf("%d", &r);
    printf("Cuántas columnas tendrá la matriz? ");
    scanf("%d", &c);
    int** mat_full = (int**) malloc(r * sizeof(int*));
    for (int i = 0; i < c; i++)
    {
        mat_full[i] = (int*) malloc(c * sizeof(int));
    }
    printf("Matriz %dx%d creada exitosamente!\n", r,c);

    // Llenando con valores random
    srand(time(NULL));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mat_full[i][j] = 1 + rand() % 100;
        }
    }

    printf("=== Matriz Original ===\n");
    print_matrix(mat_full, r, c);
    int** new_m = transpose_mat(mat_full, r, c);
    printf("=== Nueva Matriz ===\n");
    print_matrix(new_m, c, r);

    free_matrix(mat_full, r);
    free_matrix(new_m, c);
    printf("=== Nuevo Ejercicio ===\n\n");
    int p_amount;
    printf("Cuántos productos quieres? ");
    scanf("%d", &p_amount);
    Product* products = (Product*) malloc(p_amount * sizeof(Product));
    for (int i = 0; i < p_amount; i++)
    {
        printf("Producto %d\n", i+1);
        printf("Nombre: ");
        scanf("%s", products[i].name);
    }
    return 0;
}
