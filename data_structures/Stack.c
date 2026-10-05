#include "Stack.h"
#include <stdlib.h>

struct strNode
{
    Type data;
    struct strNode* prior;
};

typedef struct strNode* Node;

struct strStack
{
    Node top;
    int size;
};

Stack stack_create()
{
    Stack st = (Stack) malloc(sizeof(struct strStack));
    st->top = NULL;
    st->size = 0;

    return st;
}
