#include "data_structures/Set.h"
#include <stdio.h>

int compareInts(Type t1, Type t2)
{
    int* i1 = (int*) t1;
    int* i2 = (int*) t2;

    return *i1 - *i2;
}

void printInts(Type t1)
{
    int* i1 = (int*) t1;
    printf("%.2d ", *i1);
}

int main()
{
    int arr[] = {82,5,39,71,16,94,28,63,1,47,90,22,56,8,75,34,99,12,68,43,3,85,31,60,19,97,52,11,77,25,46,88,6,54,100,37,14,80,42,69,2,91,30,58,23,73,10,65,49,86,17,96,33,61,4,79,26,50,92,15,70,38,84,21,57,9,44,98,32,66,13,81,35,55,7,89,24,62,41,95,18,76,29,53,87,20,64,40,72,27,48,83,36,59,93,45,74,67,78,51};
    printf("Foo\n");
    Set s1 = set_create(compareInts, printInts, NULL);
    int N = sizeof(arr) / sizeof(int);

    printf("Set 1 currently has %d elements\n", set_size(s1));
    printf("Adding %d elements...\n", N);
    for (int i = 0; i < N; i++)
    {
        Bool added = set_add(s1, &arr[i]);
        printf("%s\n", added? "Añadido": "No añadido");
    }

    printf("Tamaño de set -> %d\n", set_size(s1));
    int* i2 = (int*) set_min(s1);
    printf("Smallest: %.2d\n", *i2);
    set_print(s1);

    set_destroy(s1);




    return 0;
}
