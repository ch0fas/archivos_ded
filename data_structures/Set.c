#include "Set.h"
#include "common.h"
#include <stdlib.h>
#include <stdio.h>

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
    PrintFunc pf;
    DestroyFunc df;
};

Node create_node(Type data)
{
    Node n = (Node) malloc(sizeof(struct strNode));
    n->left = n->right = NULL;
    n->data = data;

    return n;
}

Set set_create(CompareFunc cf, PrintFunc pf, DestroyFunc df)
{
    Set s = (Set) malloc(sizeof(struct strSet));
    s->root = NULL;
    s->size = 0;
    s->cf = cf;
    s->pf = pf;
    s->df = df;

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

void helper_print(Node n, PrintFunc pf)
{
    if (n == NULL) return;
    helper_print(n->left, pf);
    pf(n->data);
    helper_print(n->right, pf);
}

void helper_2print(Node n, PrintFunc pf, int spaces, char c)
{
    if (n == NULL) return;
    for (int i = 0; i < spaces; i++) printf(" ");
    printf("(%d %c) ",spaces, c);
    pf(n->data);
    printf("\n");
    helper_2print(n->left, pf, spaces + 1, 'L');
    helper_2print(n->right, pf, spaces + 1, 'R');
}

void set_print(Set s)
{
    helper_print(s->root, s->pf);
    printf("\n");
    helper_2print(s->root, s->pf, 0, 'M');
}

void helper_destroy(Node n, DestroyFunc df)
{
    if (n == NULL) return;
    helper_destroy(n->left, df);
    helper_destroy(n->right, df);
    if (df != NULL) df(n->data);
    free(n);
}

void set_destroy(Set s)
{
    helper_destroy(s->root, s->df);
    free(s);
}

Type set_min(Set s)
{
    if (s->root == NULL) return NULL;
    Node n = s->root;
    while(n->left != NULL)
    {
        n = n->left;
    }
    return n->data;
}
