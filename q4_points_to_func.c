#include <stdio.h>

typedef enum {False, True} bool;

typedef bool (*ContainsFunc)(char[], char);

bool contains(char string[], char c)
{
    return True;
}

int main()
{
    bool (*ContainsFunc)(char[], char) = contains;


    return 0;
}