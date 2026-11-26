#include "Map.h"
#include <stdio.h>
#include <stdlib.h>

struct strNode {
	Type key, value;
	struct strNode* next;
};

typedef struct strNode* Node;

struct strMap {
	HashFunc hashFunc;
	EqualsFunc equalsFunc;
	int M, size;
	Node* hashTable;
};

Map map_create(int M, HashFunc hash, EqualsFunc equals) {
	Map map = (Map) malloc(sizeof(struct strMap));
	map->hashFunc = hash;
	map->equalsFunc = equals;
	map->M = M;  // hipótesis: M es positivo
	map->size = 0;
	map->hashTable = (Node*) calloc(M, sizeof(Node));
	return map;
}

int map_size(Map map) {
	return map->size;
}

Node createNode(Type key, Type value) {
	Node n = (Node) malloc(sizeof(struct strNode));
	n->key = key;
	n->value = value;
	n->next = NULL;
	return n;
}

Bool map_put(Map map, Type key, Type value) {
	int h = map->hashFunc(key) % map->M;
	// printf("h=%d\n", h);
	Node n = map->hashTable[h]; // n - first
	if(n == NULL) {
		map->hashTable[h] = createNode(key, value);
		map->size ++;
		return True;
	}
	while(n->next != NULL) {
		if(map->equalsFunc(key, n->key)) {
			n->value = value;
			return False;
		}
		n = n->next;
	}
	// Compara con el último de la lista
	if(map->equalsFunc(key, n->key)) {
		n->value = value;
		return False;
	}
	n->next = createNode(key, value);
	map->size ++;
	return True;
}

Node getNode(Map map, Type key) {
	int h = map->hashFunc(key) % map->M;
	Node n = map->hashTable[h];
	while(n != NULL) {
		if(map->equalsFunc(key, n->key)) {
			return n;
		}
		n = n->next;
	}
	return NULL;
}

Bool map_contains(Map map, Type key) {
	return getNode(map, key) != NULL;
}

Type map_get(Map map, Type key) {
	Node n = getNode(map, key);
	return n == NULL? NULL: n->value;
}

void map_destroy(Map map) {
	for(int h = 0; h < map->M; h ++) {
		Node n = map->hashTable[h];
		while(n != NULL) {
			Node tmp = n->next;
			free(n);
			n = tmp;
		}
	}
	free(map->hashTable);
	free(map);
}

