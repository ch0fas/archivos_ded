#ifndef SET_H_
#define SET_H_

typedef void* Type;
typedef enum {False, True} Bool;
typedef int(*CompareFunc)(Type, Type);
typedef struct strSet* Set;

// Creates a new Set, specify type with the compare function
Set set_create(CompareFunc);

// Get size of Set
int get_size(Set);

// Add element to Set
Bool set_add(Set, Type);
#endif
