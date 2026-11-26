#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct strNode {
	Type data;
	struct strNode *prior, *next;
};

typedef struct strNode* Node;

struct strList {
	Node first, last, preFirst, postLast;
	size_t size;
	DestroyFunc destroyFunc;
};

List list_create(DestroyFunc df) {
	List l = (List) malloc(sizeof(struct strList));
	l->first = NULL;
	l->last = NULL;
	l->size = 0;
	l->destroyFunc = df;
	l->preFirst = (Node) malloc(sizeof(struct strNode));
	l->preFirst->prior = NULL;
	l->preFirst->data = NULL;
	l->preFirst->next = NULL;
	return l;
}

size_t list_size(List l) {
	return l->size;
}

void list_add(List l, Type t) {
	// Crear nodo que guarde a t
	Node n = (Node) malloc(sizeof(struct strNode));
	n->data = t;
	n->next = n->prior = NULL;
	// Actualizar first si es necesario (lista vacía)
	if(l->first == NULL) {
		l->first = n;
		l->preFirst->next = l->first;
		n->prior = l->preFirst;
	}
	// Vincular al nuevo nodo con el último, si existiera
	if(l->last != NULL) {
		l->last->next = n;
		n->prior = l->last;
	}
	// El nuevo nodo será el último
	l->last = n;
	// Actualizar tamaño
	l->size ++;
}

Type list_get(List l, int p) {
	if(p < 0 || p >= list_size(l)) return NULL;
	// Encontrar el nodo número p (efectuar p brincos)
	Node n = l->first;
	for(int i = 0; i < p; i ++) {
		n = n->next;  // n = n + 1
	}
	return n->data;
}

// Devuelve el dato contenido en el nodo eliminado
Type list_remove(List l, int p) {
	// La posición p no es correcta o lista vacía
	if(p < 0 || p >= list_size(l)) return NULL;
	int i;
	Type data;
	Node node;
	if(list_size(l) == 1) {  // Hay un elemento en la lista
		data = l->first->data;
		free(l->first);
		l->first = NULL;
		l->last = NULL;
	} else if(p == 0) {  // Se elimina el primero
		data = l->first->data;
		node = l->first->next;  // node es el segundo
		free(l->first);
		l->first = node;
		node->prior = NULL;
	} else if(p == list_size(l) - 1) {  // Se elimina el último
		data = l->last->data;
		node = l->last->prior;	// node es el penúltimo
		free(l->last);
		l->last = node;
		node->next = NULL;
	} else {	   // Se elimina uno de la mitad
		node = l->first;
		for(i = 0; i < p; i ++) {
			node = node->next;
		}
		data = node->data;
		node->prior->next = node->next;
		node->next->prior = node->prior;
		free(node);
	}
	l->preFirst->next = l->first;
	l->size --;
	return data;
}

void list_destroy(List list) {
	// Eliminar dato por dato, nodo por nodo
	Node n = list->first;
	Node nxt;
	while(n != NULL) {
		if(list->destroyFunc != NULL) {
//			printf("Se eliminó %d\n", *((int*) n->data));
			list->destroyFunc(n->data);
		}
		nxt = n->next;
		free(n);
//		printf("Se eliminó nodo\n");
		n = nxt;
	}
	free(list);
}

Iterator list_begin(List list) {
	return list->preFirst;
}

Bool list_hasNext(Iterator ite) {
	return ite->next != NULL;
//	if(ite->next != NULL) {
//		return True;
//	} else {
//		return False;
//	}
}

Iterator list_next(Iterator ite) {
	return ite->next;
}

Type list_data(Iterator ite) {
	return ite->data;
}

Iterator list_insert(Iterator ite, Type data, List l)
{
    if (ite == NULL) return NULL;

    Node n = (Node) malloc(sizeof(struct strNode));
    n->data = data;
    n->prior = ite;
    n->next = ite->next;

    if (ite->next != NULL)
    {
        ite->next->prior = n;
    } else
    {
        l->last = n;
    }
    ite->next = n;

    if(ite == l->preFirst) l->first = n;

    l->size++;

    return n;
}

Iterator list_delete(Iterator ite, List l)
{
    if (ite == NULL || ite == l->preFirst) return NULL;

    Node prev = (ite == l->first) ? l->preFirst: ite->prior;
    Node next = ite->next;

    prev->next = next;
    if (next != NULL)
    {
        next->prior = prev;
    } else
    {
        l->last = (prev == l->preFirst) ? NULL: prev;
    }

    if (ite == l->first) l->first = next;

    if (l->destroyFunc != NULL) l->destroyFunc(ite->data);
    l->size--;
    return prev;
}