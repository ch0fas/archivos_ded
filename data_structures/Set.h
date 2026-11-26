#ifndef SET_H_
#define SET_H_

#include "common.h"

typedef struct strSet* Set;

Set set_create(CompareFunc, PrintFunc, DestroyFunc);
int set_size(Set);
Bool set_add(Set, Type);
Bool set_contains(Set, Type);
void set_print(Set);
void set_destroy(Set);
Type set_min(Set);
Type set_max(Set);
int set_level(Set s, Type data);
Bool set_insert(Set s, Type data);


#endif /* SET_H_ */
