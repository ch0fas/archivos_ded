#include "data_structures/common.h"
#ifndef CHACK_H_
#define CHACK_H_

typedef struct strChack* Chack;

Chack chack_create(int capacity);
void chack_destroy(Chack);
void chack_push(Chack, char);
char chack_pop(Chack);
char chack_top(Chack);
Bool chack_isEmpty(Chack);
void chack_clear(Chack);
int chack_size(Chack);
void chack_print(Chack);

#endif