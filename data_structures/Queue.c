#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

struct strNode
{
    Type data;
    struct strNode* next;
};

typedef struct strNode* Node;

struct strQueue
{
    Node first, last;
    int size;
};

Queue queue_create()
{
    Queue q = (Queue) malloc(sizeof(struct strQueue));
    q->first = NULL;
    q->last = NULL;
    q->size = 0;

    return q;
}

void queue_destroy(Queue q)
{
    Node bye_node, next_node;
    bye_node = q->first;
    while (bye_node != NULL)
    {
        next_node = bye_node->next;
        free(bye_node);
        bye_node = next_node;
    }

    free(q);
}

int queue_size(Queue q)
{
    return q->size;
}

Bool queue_isEmpty(Queue q)
{
    return q->first == NULL;
}

Type queue_peek(Queue q)
{
    if (queue_isEmpty(q)) return NULL;

    return q->first->data;
}

void queue_offer(Type data, Queue q)
{
    Node tn = (Node) malloc(sizeof(struct strNode));
    tn->data = data;
    tn->next = NULL;

    if (queue_isEmpty(q))
    {
        q->first = tn;
    } else
    {
        q->last->next = tn;
    }

    q->last = tn;
    q->size++;

}

Type queue_poll(Queue q)
{
    if (queue_isEmpty(q)) return NULL;

    Node n_toPoll = q->first;

    Type data = n_toPoll->data;
    q->first = n_toPoll->next;

    free(n_toPoll);
    q->size--;

    return data;
}
