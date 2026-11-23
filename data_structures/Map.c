#include "Map.h"
#include "common.h"
#include <stdlib.h>

struct strNode
{
    Type key, value;
    struct strNode* next;
};

typedef struct strNode* Node;

struct strMap
{
    HashFunc hf;
    EqualsFunc ef;
    int M, size;
    Node* hash_table;
};

Node get_node(Map map, Type key)
{
    int h = map->hf(key) % map->M;
    Node n = map->hash_table[h];
    while (n != NULL)
    {
        if (map->ef(key, n->key))
        {
            return n;
        }
        n = n->next;
    }
    return NULL;
}

Node create_node(Type key, Type value)
{
    Node n = (Node) malloc(sizeof(struct strNode));
    n->key = key;
    n->value = value;
    n->next = NULL;

    return n;
}

Map map_create(int m, HashFunc hf, EqualsFunc ef)
{
    Map map = (Map) malloc(sizeof(struct strMap));
    map->M = m;
    map->hf = hf;
    map->ef = ef;
    map->size = 0;
    map->hash_table = (Node*) calloc(m,sizeof(Node));

    return map;
}

int map_size(Map map)
{
    return map->size;
}

Bool map_put(Map map, Type key, Type value)
{
    int h = map->hf(key);
    Node n = map->hash_table[h]; // First
    if (n == NULL)
    {
        map->hash_table[h] = create_node(key, value);
        map->size++;
        return True;
    }

    while (!map->ef(key, n->key))
    {
        if (map->ef(key, n->key))
        {
            n->value = value;
            return False;
        }
        n = n->next;
    }

    if (map->ef(key, n->key))
    {
        n->value = value;
        return False;
    }
    n->next = create_node(key, value);
    map->size++;
    return True;
}

Bool map_contains(Map map, Type key)
{
    return get_node(map, key) != NULL;
}

Type map_get(Map map, Type key)
{
    Node n = get_node(map, key);
    return n == NULL? NULL : n->value;
}
