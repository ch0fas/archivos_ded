#include <stdio.h>
#include <math.h>
#include "data_structures/Map.h"

int intHash(Type t)
{
    int* key = (int*) t;
    return fabs (*key);
}

Bool intEquals(Type t1, Type t2)
{
    int* i1 = (int*) t1;
    int* i2 = (int*) t2;
    return *i1 == *i2;
}

int floatHash(Type t)
{
    float* key = (float*) t;
    return (int) fabs (*key * 1000);
}

int main()
{
    const int M = 100;
    Map m1 = map_create(M, intHash, intEquals);
    int keys[] = {1,2,3,4,5,6,7,8,5,3};
    int values[] = {1,2,7,24,121,720,5040,40320,121,6};
    int n = sizeof(keys) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        Bool added = map_put(m1, keys + i, values + i);
        if (added)
        {
            printf("KEY -> %d, VALUE -> %d\n", *(keys + i), *(values + i));
        }
    }
    printf("Size -> %d\n", map_size(m1));

    int* value = (int*)map_get(m1, keys+3);
    printf("Valor de key = 4 -> %d\n", *value);
    return 0;
}
