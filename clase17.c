#include <stdio.h>
#include "data_structures/Queue.h"

int main()
{
    int arr[] = {1,2,3,4,5};
    Queue q1 = queue_create();

    printf("Is empty? %d\n", queue_isEmpty(q1));

    for (int i = 0; i < 5; i++)
    {
        queue_offer(arr + i, q1);
    }

    printf("Size -> %d\n", queue_size(q1));
    printf("Is empty again? %d\n", queue_isEmpty(q1));

    int* peek = (int*) queue_peek(q1);
    printf("Peeking -> %d\n", *peek);

    int* polled = (int*) queue_poll(q1);
    printf("Polled Value -> %d\n", *polled);
    printf("New Size -> %d\n", queue_size(q1));


    return 0;
}
