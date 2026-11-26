#include <stdio.h>
#include "data_structures/List.h"
#include "data_structures/Set.h"

int compare_ints(Type t1, Type t2)
{
    int* i1 = (int*) t1;
    int* i2 = (int*) t2;

    return *i1 - *i2;
}

void print_int(Type t)
{
    int *i = (int*) t;
    printf("%d", *i);
}

int main()
{
    printf("=== RETO 1 ===\n");
    int arr[] = {1,2,3,4,5,6,7,8,9};
    List l1 = list_create(NULL);

    for (int i = 0; i < 9; i++)
    {
        list_add(l1, arr+i);
    }
    Iterator ite1 = list_begin(l1);
    while(list_hasNext(ite1))
    {
        ite1 = list_next(ite1);
        int* val = list_data(ite1);
        if (*val % 2 == 0)
        {
            ite1 = list_delete(ite1, l1);
        } else
        {
            int* i = (int*) malloc(sizeof(int));
            *i = *val + 100;
            ite1 = list_insert(ite1, i, l1);
        }
    }

    ite1 = list_begin(l1);
    while(list_hasNext(ite1))
    {
        ite1 = list_next(ite1);
        int* value = list_data(ite1);
        printf("%d", *value);
        printf(list_hasNext(ite1) ? ", ": "\n");
    }
    printf("Final Size -> %zu\n", list_size(l1));

    printf("=== RETO 2 ===\n");

    int arr2[] = {7,1,9,4,8,2,5,8,4,3}; // 10 values
    Set s1 = set_create(compare_ints, print_int, NULL);
    for (int i = 0; i < 10; i++)
    {
        Bool flag = set_insert(s1, arr2 + i);
        printf("Insert? %s\n", flag ? "Yes" : "No");
    }

    set_print(s1);

    int test2[] = {7,1,9,4,8,2,5,8,4,3,11,12};
    for (int i = 0; i < 12; i++)
    {
        printf("Level of %d -> %d\n", *(test2 + i), set_level(s1, test2 + i));
    }


    return 0;
}