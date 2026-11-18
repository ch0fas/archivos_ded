#include <stdio.h>
#include "data_structures/PriorityQueue.h"

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
    int data[] = {0,6,3,9,1,4,7,10,6,3,9};
    size_t C = 10;
    PrioQueue pq = pqueue_create(C, compare_ints);
    int N = sizeof(data) / sizeof(int);

    for (int i = 0; i < N; i++)
    {
        pqueue_offer(pq, data+i);
        int* min = (int*) pqueue_peek(pq);
        printf("min=%d\n", *min);
    }
    pqueue_print(pq, print_int);

    return 0;
}
