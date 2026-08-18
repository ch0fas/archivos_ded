#include <stdio.h>

int main()
{
    char c1 = 'A';
    char* pc1;

    pc1 = &c1;
    printf("%p\n", pc1);
    *pc1 = 'B';
    printf("After changing with the pointer: %c\n", c1);

    char c2 = '6';
    pc1 = &c2;
    *pc1 = '7';
    printf("%c\n", c1);
    printf("%c\n", c2);

    printf("%ld\n", sizeof(double));
    return 0;
}