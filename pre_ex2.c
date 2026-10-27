#include <stdio.h>
#include <stdlib.h>
#define R 10
#define C 10

int* clone(int* src, int N)
{
    int* dst = (int*) malloc(N * sizeof(int));
    int* ptr1 = src;
    int* ptr2 = dst;
    for (int i = 0; i < N; i++)
    {
        *ptr2 = *ptr1;
        ptr1++;
        ptr2++;
    }

    return dst;
}

void free_info(int** matrix, int r)
{
    for (int i = 0; i < r; i++)
    {
        free(matrix[i]);
    }

    free(matrix);
}

void toLowerCase(char* str)
{
    char* ptr = str;
    char* dst
    while (*ptr != '\0')
    {

    }
}

int main()
{
    // int* src = (int*) malloc(10 *sizeof(int));
    // for (int i = 0; i < 10; i++)
    // {
    //     src[i] = i;
    // }

    // int* dst = clone(src, 10);
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d", dst[i]);
    // }

    // int** matrix = (int**) malloc(R * sizeof(int*));

    // for (int i = 0; i < R; i++)
    // {
    //     matrix[i] = (int*) malloc(C * sizeof(int));
    // }

    // free_info(matrix, R);

    return 0;
}