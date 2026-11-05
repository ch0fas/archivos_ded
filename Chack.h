#ifndef CHACK_H_
#define CHACK_H_

typedef struct strChack* Chack;
typedef enum {False, True} Bool;

Chack chack_create(int capacity);
void chack_push(Chack, char);
char chack_pop(Chack);
char chack_top(Chack);
Bool chack_isEmpty(Chack);
void chack_clear(Chack);
int chack_size(Chack);
void chack_print(Chack);

#endif