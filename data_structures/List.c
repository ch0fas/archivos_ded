#include "List.h"
#include <stddef.h>
#include <stdlib.h>

struct strNode
{
    Type data;
    struct strNode *prior, *next;
};

typedef struct strNode* Node;

struct strList
{
    Node first, last;
    size_t size;
};

List list_create()
{
    List l = (List) malloc(sizeof(struct strList));
    l->first = NULL;
    l->last = NULL;
    l->size = 0;

    return l;
}

size_t list_size(List l)
{
    return l->size;
}

void list_add(List l, Type data)
{
    Node new = (Node) malloc(sizeof(struct strNode));
    new->data = data;

    if (l->size == 0)
    {
        l->first = new;
        new->prior = NULL;
    } else
    {
        new->prior = l->last;
        l->last = new;
    }
    new->next = NULL;
}

Type list_get(List l, int p)
{
    if (p == 0)
    {
        return l->first->data;
    } else if (p == (l->size - 1))
    {
        return l->last->data;
    } else
    {
        Node res = l->first;
        for (int i = 1; i < l->size; i++)
        {
            res = res->next;
            if (i == p)
            {
                return res->data;
            }
        }
    }
    return NULL;
}
