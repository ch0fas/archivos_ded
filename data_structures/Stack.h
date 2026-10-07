#ifndef STACK_H_
#define STACK_H_

typedef void* Type;
typedef enum {False, True} Bool;

typedef struct strStack* Stack;

// Creates the stack
Stack stack_create(); // Done
void stack_destroy(Stack);

// Add element to the stack
void stack_push(Type, Stack); // Done
Type stack_top(Stack); // Done
void stack_pop(Stack); // Done
Bool stack_isEmpty(Stack); // Done
int stack_size(Stack); // Done

#endif
