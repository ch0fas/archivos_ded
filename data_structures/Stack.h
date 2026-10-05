#ifndef STACK_H_
#define STACK_H_

typedef void* Type;
typedef enum {False, True} Bool;

typedef struct strStack* Stack;

Stack stack_create();
void stack_push(Type, Stack);
Type stack_top(Stack);
void stack_pop(Stack);
Bool stack_isEmpty(Stack);
int stack_size(Stack);

#endif
