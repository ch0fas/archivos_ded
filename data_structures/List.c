#include "List.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

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
        l->last = new;
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

Type list_remove(List l, int p)
{
    if (p < 0 || p >= list_size(l))
    {
        printf("Invalid position\n");
        return NULL;
    }

    Type data;
    Node tmp_node;
    if (list_size(l) == 1)
    {
        data = l->first->data;
        free(l->first);
        l->first = NULL;
        l->last = NULL;
    } else if (p == 0)
    {
        data = l->first->data;
        tmp_node = l->first->next;
        free(l->first);
        l->first = tmp_node;
        tmp_node->prior = NULL;
    } else if (p == (list_size(l)-1))
    {
        data = l->last->data;
        tmp_node = l->last->prior;
        free(l->last);
        l->last = tmp_node;
        tmp_node->next = NULL;
    } else
    {
        tmp_node = l->first;
        for (int i = 0; i < p; i++)
        {
            tmp_node = tmp_node->next;
        }
        data = tmp_node->data;
        tmp_node->prior->next = tmp_node->next;
        tmp_node->next->prior = tmp_node->prior;
        free(tmp_node);
    }

    l->size--;
    return data;
}
