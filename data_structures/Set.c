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

Node create_node(Type data)
{
    Node n = (Node) malloc(sizeof(struct strNode));
    n->left = n->right = NULL;
    n->data = data;

    return n;
}

Set set_create(CompareFunc cf)
{
    Set s = (Set) malloc(sizeof(struct strSet));
    s->root = NULL;
    s->size = 0;
    s->cf = cf;

    return s;
}

int set_size(Set s)
{
    return s->size;
}

Bool set_add(Set s, Type data)
{
    Bool found = False;
    Bool added = False;
    if (s->root == NULL)
    {
        s->root = create_node(data);
        added = True;
    } else
    {
        Node curr = s->root;
        while(!found )
        {
            int res = s->cf(data, curr->data);
            if (res == 0) found = True;
            else if (res < 0)
            {
                if (curr->left == NULL)
                {
                    curr->left = create_node(data);
                    added = True;
                } else
                {
                    curr = curr->left;
                }

            } else
            {
                if (curr->right == NULL)
                {
                    curr->right = create_node(data);
                    added = True;
                } else
                {
                    curr = curr->right;
                }
            }
        }
    }

    if (added)
    {
        s->size++;
    }
    return added;
}

Bool contains(Node n, Type data, CompareFunc cf)
{
    if (n == NULL) return False;
    int res = cf(data, n->data);
    if (res == 0) return True;
    if (res < 0) return contains(n->left, data, cf);
    return contains(n->right, data, cf);
}
Bool set_contains(Set s, Type data)
{
    return contains(s->root, data, s->cf);
}
