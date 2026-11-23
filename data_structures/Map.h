

#ifndef MAP_H_
#define MAP_H_
#include "common.h"

typedef struct strMap* Map;

Map map_create(int m, HashFunc hf, EqualsFunc ef);
int map_size(Map map);
Bool map_put(Map map, Type key, Type value);
Bool map_contains(Map map, Type key);
Type map_get(Map map, Type key);

#endif
