#ifndef LIST_H_
#define LIST_H_

#include "common.h"
#include <stdlib.h>

typedef struct strList* List;

List list_create(DestroyFunc);
size_t list_size(List);
void list_add(List, Type);
Type list_get(List, int);
Type list_remove(List l, int p);
void list_destroy(List);

typedef struct strNode* Iterator;

Iterator list_begin(List);
Bool list_hasNext(Iterator);
Iterator list_next(Iterator);
Type list_data(Iterator);
Iterator list_insert(Iterator ite, Type data, List l);
Iterator list_delete(Iterator ite, List l);


#endif /* LIST_H_ */
