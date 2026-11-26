#include <stdio.h>
#include <stdlib.h>
#include "Set.h"
#include "common.h"

struct strNode {
	Type data;
	struct strNode *left, *right;
};

typedef struct strNode* Node;

struct strSet {
	Node root;
	size_t size;
	CompareFunc compare;
	PrintFunc print;
	DestroyFunc destroy;
};

Set set_create(CompareFunc cf, PrintFunc pf, DestroyFunc df) {
	Set set = (Set) malloc(sizeof(struct strSet));
	set->root = NULL;
	set->size = 0;
	set->compare = cf;
	set->print = pf;
	set->destroy = df;
	return set;
}

int set_size(Set set) {
	return set->size;
}

Node create_node(Type t) {
	Node n = (Node) malloc(sizeof(struct strNode));
	n->left = n->right = NULL;
	n->data = t;
	return n;
}

Bool set_add(Set s, Type t) {
	Bool found = False, added = False;
	// Caso base: el árbol está vacío
	if(s->root == NULL) {
		s->root = create_node(t);
		added = True;
	} else {
	// Caso general: el árbol no está vacío
		Node curr = s->root;
		while(!found && !added) {
			int res = s->compare(t, curr->data);
			if(res == 0) {  	// t = curr->data
				found = True;
			}
			else if(res < 0) {	// t < curr->data
				if(curr->left == NULL) {
					curr->left = create_node(t);
					added = True;
				} else {
					curr = curr->left;
				}
			} else {			// t > curr->data
				if (curr->right == NULL) {
					curr->right = create_node(t);
					added = True;
				} else {
					curr = curr->right;
				}
			}
		}
	}
	if(added) {
		s->size ++;
	}
	return added;
}

Bool contains(Node n, Type t, CompareFunc compare) {
	if(n == NULL) return False;
	int res = compare(t, n->data);
	if(res == 0) return True;
	if(res < 0) return contains(n->left, t, compare);
	return contains(n->right, t, compare);
}

Bool set_contains(Set s, Type t) {
	return contains(s->root, t, s->compare);
}

// Imprimir de menor a mayor
void print_inorder(Node n, PrintFunc print) {
	if(n == NULL) return;
	print_inorder(n->left, print);
	print(n->data);
	print_inorder(n->right, print);
}

// Imprimir con información estructural
void print_preorder(Node n, PrintFunc print, int spaces, char c) {
	if(n == NULL) return;
	for(int s = 0; s < spaces; s ++) printf(" ");
	printf("(%c) ", c);
	print(n->data);
	printf("\n");
	print_preorder(n->left, print, spaces + 2, 'L');
	print_preorder(n->right, print, spaces + 2, 'R');
}

void set_print(Set s) {
	print_preorder(s->root, s->print, 0, 'G');
	printf("\n");
}

void node_destroy(Node n, DestroyFunc destroi ){
	if(n==NULL)return;
	node_destroy(n->left, destroi);
	node_destroy(n->right, destroi);
	if(destroi != NULL) destroi(n->data);
	free(n);
}

void set_destroy(Set s) {
	node_destroy(s->root,s->destroy);
	free(s);
}

Type set_min(Set s) {
	if(s == NULL || s->root == NULL) return NULL;
	Node n = s->root;
	while(n->left != NULL){
		n = n->left;
	}
	return n->data;
}

Type Nmax(Node n) {
if(n->right==NULL) return n->data;
return Nmax(n->right);



}
Type set_max(Set s) {
	if(s== NULL) return NULL;
	return Nmax(s->root);
}

int set_level(Set s, Type data)
{
    Node curr = s->root;
    int level = 1;

    while(curr != NULL)
    {
        int res = s->compare(data, curr->data);
        if (res == 0) return level;
        curr = (res < 0) ? curr->left : curr->right;
        level++;
    }
    return -1;
}


Node insert(Node n, Type data, CompareFunc cf, Bool* added)
{
    if (n == NULL)
    {
        *added = True;
        return create_node(data);
    }

    int res = cf(data, n->data);
    if (res < 0)
    {
        n->left = insert(n->left, data, cf, added);
    } else if (res > 0)
    {
        n->right = insert(n->right, data, cf, added);
    }
    return n;
}

Bool set_insert(Set s, Type data)
{
    Bool added = False;
    s->root = insert(s->root, data, s->compare, &added);
    if(added) s->size++;
    return added;
}
