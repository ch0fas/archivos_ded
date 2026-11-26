#include "PriorityQueue.h"
#include <stdlib.h>

struct strPQueue {
	Type* heap; // ¿Qué era esto?
	size_t capacity;
	size_t size;
	CompareFunc compare;
};

PQueue pqueue_create(size_t capacity, CompareFunc compare) {
	//Creamos el blque de memoria
    PQueue new = (PQueue) malloc(sizeof (struct strPQueue));
	new->heap = (Type*) calloc(capacity,sizeof(Type)); //arreglo nulo? ,o que
	//Mis compañeros me dijieron que un calloc profe
	new->capacity=capacity;
	new->size=0;
	new->compare=compare;
	return new;
}

Bool pqueue_isEmpty(PQueue pqueue){
	return pqueue->size == 0;
}

size_t pqueue_size(PQueue pqueue) {
	return pqueue->size;
}

int parent(int index) {
	return (index - 1) / 2;
}

void suap(Type *a, Type *b) {
	Type tmp = *a;
	*a = *b;
	*b = tmp;
}

void pqueue_offer(PQueue pqueue, Type data) {
//	Hipótesis: hay capacidad en el arreglo (sólo falta apoyarlos)
	pqueue->heap[pqueue->size] = data;
	int c = pqueue->size, p = parent(c);
	int res = -1;
	while(c > 0 && res < 0) {
		res = pqueue->compare(pqueue->heap[c], pqueue->heap[p]);
		if(res < 0) {  //  El hijo es menor que el papá
			suap(&pqueue->heap[c], &pqueue->heap[p]);
			c = p;
			p = parent(p);
		}
	}
	pqueue->size ++;
}

Type pqueue_peek(PQueue pqueue) {
	if(pqueue_isEmpty(pqueue)) return NULL;
	return pqueue->heap[0];
}

void pqueue_print(PQueue pqueue, PrintFunc print) {
	for(int i = 0; i < pqueue->size; i ++) {
		print(pqueue->heap[i]);
		if(i < pqueue->size - 1) {
			printf(", ");
		}
	}
	printf("\n");
	printf("Originario de la ciudad de Nueva York\n");
	printf("Solo que sin construir\n");
}

int left(int index) {
	return 2 * index + 1;
}

int right(int index) {
	return 2 * index + 2;
}

void heapify(PQueue pqueue, int p) {
	// Encontrar menor entre padre, izquierdo, derecho
	int l = left(p), r = right(p);
	int m = p;
	Type pd = pqueue->heap[p];
	if(l < pqueue->size) {
		Type ld = pqueue->heap[l];
		int res = pqueue->compare(pd, ld);
		if(res > 0) m = l;
	}
	if(r < pqueue->size) {
		Type rd = pqueue->heap[r];
		int res = pqueue->compare(pqueue->heap[m] , rd);
		if(res > 0) m = r;
	}
	// En este momento, m es la posición del menor de los 3
	if(m != p) {
		suap(&pqueue->heap[m], &pqueue->heap[p]);
		heapify(pqueue, m);
	}
}

Type pqueue_poll(PQueue pqueue) {
	if(pqueue_isEmpty(pqueue)) return NULL;
	Type min = pqueue->heap[0];
	pqueue->size --;
	pqueue->heap[0] = pqueue->heap[pqueue->size];
	heapify(pqueue, 0);
	return min;
}
