#include "data_structures/Set.h"
#include <stdio.h>

int compareInts(Type t1, Type t2)
{
    int* i1 = (int*) t1;
    int* i2 = (int*) t2;

    return *i1 - *i2;
}

int main()
{
    int arr[] = {6,3,8,1,5,7,10,4, 6, 8, 1};
    printf("Foo\n");
    Set s1 = set_create(compareInts);
    int N = sizeof(arr) / sizeof(int);

    printf("Set 1 currently has %d elements\n", set_size(s1));
    printf("Adding %d elements...\n", N);
    for (int i = 0; i < N; i++)
    {
        Bool added = set_add(s1, &arr[i]);
        printf("%s\n", added? "Añadido": "No añadido");
    }


    return 0;
}
