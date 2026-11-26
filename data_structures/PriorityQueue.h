#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "common.h"
#include <stdio.h>

typedef struct strPQueue* PQueue;

PQueue pqueue_create(size_t, CompareFunc);
size_t pqueue_size(PQueue);
Bool pqueue_isEmpty(PQueue);
void pqueue_offer(PQueue, Type);
Type pqueue_peek(PQueue);
Type pqueue_poll(PQueue);
void pqueue_print(PQueue, PrintFunc);
void pqueue_destroy(PQueue);

#endif /* PRIORITYQUEUE_H_ */
