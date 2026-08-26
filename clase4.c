#include <stdio.h>

#define COLS 3

void print_matrix(int mat[][COLS], int rows)
{
    int* pm = *mat;
    // int* pm = &mat[0][0]; also works
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%2d", *pm);
            pm++;
        }
        printf("\n");
    }
}

int main()
{
    int x = 150;
    int arr[] = {10,20,30,40,50};

    int* pa0 = arr;
    int* pa3 = arr + 3;

    int* px = &x;
    int** ppx = &px;
    printf("%p\n", px);
    printf("%p\n", ppx);

    int y = *px;
    int* pk = *ppx;
    printf("%d\n", y);
    printf("%p\n", pk);

    printf("=== ARREGLOS ===\n\n");
    printf("%d\n", *pa0);
    printf("%d\n", *pa3);
    *pa3 += 3;
    printf("%d\n", arr[3]);
    int diff = pa3 - pa0;
    printf("%d\n", diff);

    printf("=== MATRICES ===\n\n");
    int mat[2][COLS] = { {1,2,3}, {4,5,6}};
    int mat2[3][COLS] = { {1,2,3}, {4,5,6}, {7,8,9}};

    print_matrix(mat, 2); printf("\n");
    print_matrix(mat2, 3);

    return 0;
}
