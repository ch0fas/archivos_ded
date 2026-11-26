#ifndef MAP_H_
#define MAP_H_

#include "common.h"

typedef struct strMap* Map;

Map map_create(int M, HashFunc, EqualsFunc);
int map_size(Map);
Bool map_put(Map, Type key, Type value);
Bool map_contains(Map, Type key);
Type map_get(Map, Type key);
void map_destroy(Map);

#endif /* MAP_H_ */
