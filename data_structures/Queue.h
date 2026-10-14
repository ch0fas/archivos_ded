#ifndef QUEUE_H_
#define QUEUE_H_

typedef void* Type;
typedef enum {False, True} Bool;

typedef struct strQueue* Queue;

// Creates an empty Queue
Queue queue_create();

// Destroys a Queue
void queue_destroy(Queue);

// Get size of queue
int queue_size(Queue);

// Check is Queue is Empty
Bool queue_isEmpty(Queue);

// Get latest element in Queue
Type queue_peek(Queue);

// Add value to queue
void queue_offer(Type, Queue);

// Delete item at front of Queue and get it
Type queue_poll(Queue);

#endif
