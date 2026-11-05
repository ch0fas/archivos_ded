#include "Chack.h"
#include <stdlib.h>
#include <stdio.h>

struct strChack
{
    char* data;
    size_t size;
    size_t capacity;
};

Chack chack_create(int capacity)
{
    size_t init_capacity;
    if (capacity < 3)
    {
        init_capacity = 3;
    } else init_capacity = capacity;
    Chack k = (Chack) malloc(sizeof(struct strChack));
    k->data = (char*) malloc(init_capacity * sizeof(char));
    k->size = 0;
    k->capacity = init_capacity;

    return k;
}

void chack_push(Chack k, char data)
{
    k->data[k->size] = data;
    k->size++;
    if (k->size == k->capacity)
    {
        k->capacity = k->capacity * 2;
        k->data = realloc(k->data, (k->capacity * sizeof(char)));
    }
}

char chack_pop(Chack k)
{
    if (k->size == 0) return 0;

    char res = k->data[k->size-1];
    k->size--;

    return res;
}

char chack_top(Chack k)
{
    if (k->size == 0) return 0;

    return k->data[k->size-1];
}

Bool chack_isEmpty(Chack k)
{
    return k->size == 0;
}

void chack_clear(Chack k)
{
    for (int i = 0; i < k->size+1; i++)
    {
        k->data[i] = '\0';
    }
    k->size = 0;
}

int chack_size(Chack k)
{
    return k->size;
}

void chack_print(Chack k)
{
    if (k->size == 0)
    {
        printf("Empty Chack!\n");
        return;
    } else
    {
        printf("[");
        for (int i = k->size-1; i >= 0; i--)
        {
            printf("%c", k->data[i]);
        }
        printf("]\n");
    }
}