#include <stdio.h>
#include "data_structures/Stack.h"

int main()
{
    int data[] = {1,2,3,4,10};
    Stack st1 = stack_create();

    printf("%d\n", stack_size(st1));

    stack_top(st1);
    printf("Foo\n");

    stack_push(data, st1);
    stack_push(data + 1, st1);
    stack_push(data + 2, st1);
    stack_push(data + 3, st1);
    stack_push(data + 4, st1);
    int x = 20;
    stack_push(&x, st1);
    printf("New Size: %d\n", stack_size(st1));

    int* top = (int*) stack_top(st1);
    printf("Valor más reciente: %d\n", *top);

    printf("=== POPPING (like Nav)... ===\n");
    stack_pop(st1);
    int* top2 = (int*) stack_top(st1);
    printf("New Size: %d\nNew Top: %d\n", stack_size(st1), *top2);

    printf("Emptying the rest of the stack, not knowing its size for sure\n");

    while(!stack_isEmpty(st1))
    {
        printf("Deleting -> %d\n", *((int*)stack_top(st1)));
        stack_pop(st1);
    }

    stack_destroy(st1);

    printf("=== Creating new Stack ===\n");
    Stack st2 = stack_create();
    char name1[] = "Sofia";
    char name2[] = "Maldonado";
    char name3[] = "García";

    stack_push(name1, st2);
    stack_push(name2, st2);
    stack_push(name3, st2);

    printf("Top: %s\n", (char*)stack_top(st2));
    stack_pop(st2);
    printf("Top: %s\n", (char*)stack_top(st2));
    stack_pop(st2);
    printf("Top: %s\n", (char*)stack_top(st2));
    stack_pop(st2);

    stack_destroy(st2);

    return 0;
}
