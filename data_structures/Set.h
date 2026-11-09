#ifndef SET_H_
#define SET_H_
#include "common.h"

typedef int(*CompareFunc)(Type, Type);
typedef struct strSet* Set;

// Creates a new Set, specify type with the compare function
Set set_create(CompareFunc, PrintFunc, DestroyFunc);

// Get size of Set
int set_size(Set);

// Add element to Set
Bool set_add(Set, Type);

// Check if element is in Set
Bool set_contains(Set, Type);

// Prints the contents of the Set
void set_print(Set);

// Eliminiates a Set from memory, along with its nodes
void set_destroy(Set);

// returns the smallest number in the Set
Type set_min(Set);

#endif
