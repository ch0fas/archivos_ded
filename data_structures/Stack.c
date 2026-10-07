#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

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

void destroy(Node n) // Helper function
{
    if (n == NULL) return;
    free(n->prior);
    free(n);
}

Stack stack_create()
{
    Stack st = (Stack) malloc(sizeof(struct strStack));
    st->top = NULL;
    st->size = 0;

    return st;
}



void stack_destroy(Stack st)
{
    printf("Destorying Stack...\n");
    destroy(st->top);
    free(st);
    printf("Stack Was Destroyed\n");
}

void stack_push(Type data, Stack st)
{
    Node tn = (Node) malloc(sizeof(struct strNode));
    tn->data = data;
    tn->prior = st->top;
    st->top = tn;
    st->size++;
}

Type stack_top(Stack st)
{
    if (st->top == NULL) return NULL;
    else return st->top->data;
}

void stack_pop(Stack st)
{
    if (stack_isEmpty(st)) return;

    Node temp = st->top;
    st->top = st->top->prior;

    free(temp);
    st->size--;
}

Bool stack_isEmpty(Stack st)
{
    return st->top == NULL;
    // return st->size == 0; también es una solución válida
}

int stack_size(Stack st)
{
    return st->size;
}
