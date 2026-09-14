#include <stdio.h>

typedef enum {False, True} bool;

typedef bool (*ContainsFunc)(char[], char);

bool contains(char string[], char c)
{
    return True;
}

int main()
{
    ContainsFunc cf1 = contains;


    return 0;
}
