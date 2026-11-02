#include "Set.h"
#include <stdlib.h>

struct strNode
{
    Type data;
    struct strNode *left, *right;
};

typedef struct strNode* Node;

struct strSet
{
    Node root;
    size_t size;
    CompareFunc cf;
};

int compareInts(Type t1, Type t2)
{
    int* i1 = (int*) t1;
    int* i2 = (int*) t2;

    return *i1 - *i2;
}

Set set_create(CompareFunc cf)
{
    Set s = (Set) malloc(sizeof(struct strSet));
    s->root = NULL;
    s->size = 0;
    s->cf = cf;

    return s;
}

int get_size(Set s)
{
    return s->size;
}

Bool set_add(Set s, Type data)
{
    if (s->size == 0)
    {
        Node tmp = (Node) malloc(sizeof(struct strNode));
        tmp->data = data;
        tmp->left = NULL;
        tmp->right = NULL;
        s->size++;
        return True;
    }

    return NULL;
}
