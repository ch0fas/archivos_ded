#include "common.h"
#include <stdlib.h>

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

typedef struct strPQueue* PrioQueue;

// Creates an empty PriorityQueue
PrioQueue pqueue_create(size_t, CompareFunc);

// Adds element to PriorityQueue
void pqueue_offer(PrioQueue, Type);

// See top element of PriorityQueue
Type pqueue_peek(PrioQueue);

// Delete top element of PriorityQueue, and get it
Type pqueue_poll(PrioQueue);

// Check size of PriorityQueue
size_t pqueue_size(PrioQueue);

// Check if PriorityQueue is empty
Bool pqueue_isEmpty(PrioQueue);

// Destroy PriorityQueue
void pqueue_destroy(PrioQueue);
#endif
