#include <stddef.h>

#ifndef LIST_H_
#define LIST_H_

typedef void* Type;
typedef enum {False, True} Bool;

typedef struct strList* List;

// Creates an empty list
List list_create();

// Destroys a list
void list_destroy(List);

// Get size of list
size_t list_size(List);

// Add new element to front of list
void list_add(List, Type);

// Get element at a specific position
Type list_get(List, int);

// Remove element at a specific position
Type list_remove(List, int);

#endif
