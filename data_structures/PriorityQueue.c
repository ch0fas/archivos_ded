#include "common.h"
#include "PriorityQueue.h"
#include <stdlib.h>

struct strPQueue
{
    Type* heap;
    size_t capacity;
    size_t size;
    CompareFunc cf;
};

PrioQueue pqueue_create(size_t capacity, CompareFunc cf)
{
    PrioQueue pq = (PrioQueue) malloc(sizeof(struct strPQueue));
    pq->heap = (Type*) malloc(capacity * sizeof(Type));
    pq->capacity = capacity;
    pq->size = 0;
    pq->cf = cf;

    return pq;
}

int mom(int index) {return (index - 1) / 2;}

void swap(Type* a, Type* b)
{
    Type tmp = *a;
    *a = *b;
    *b = tmp;
}

void pqueue_offer(PrioQueue pq, Type data)
{
    // Caso: Hay capacidad en el arreglo, solo hay que agregar el valor
    pq->heap[pq->size] = data;

    int child = pq->size, parent = mom(child);
    int res = -1;
    while (res < 0 && child > 0)
    {
        res = pq->cf(pq->heap[child], pq->heap[parent]);
        if (res < 0)
        {
            swap(&pq->heap[child], &pq->heap[parent]);
            child = parent;
            parent = mom(parent); // TO BE COMPLETED
        }
    }
    pq->size++;
    if (pq->size == pq->capacity)
    {
        NULL;
    }
}

Type pqueue_peek(PrioQueue pq)
{
    if (pqueue_isEmpty(pq)) return NULL;
    return pq->heap[0];
}

size_t pqueue_size(PrioQueue pq)
{
    return pq->size;
}

Bool pqueue_isEmpty(PrioQueue pq)
{
    return pq->size == 0;
}
