#include "data_structures/Set.h"

int compareInts(Type t1, Type t2)
{
    int* i1 = (int*) t1;
    int* i2 = (int*) t2;

    return *i1 - *i2;
}

int main()
{
    Set s1 = set_create(compareInts);

    return 0;
}
