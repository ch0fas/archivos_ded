#ifndef SET_H_
#define SET_H_

typedef void* Type;
typedef enum {False, True} Bool;
typedef int(*CompareFunc)(Type, Type);
typedef struct strSet* Set;

// Creates a new Set, specify type with the compare function
Set set_create(CompareFunc);

// Get size of Set
int set_size(Set);

// Add element to Set
Bool set_add(Set, Type);

// Check if element is in Set
Bool set_contains(Set, Type);

// Eliminiates a Set from memory
void set_destroy(Set s);

#endif
