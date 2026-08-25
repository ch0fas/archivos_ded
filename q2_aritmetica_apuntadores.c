#include <stdio.h>

int main()
{
    char c[] = {'a','b','c','d'};
    char *pc = c;
    printf("Valor al que apunta pc: %c\n", *pc);
    *pc = 'A';
    printf("Valor del primer elemento en c: %c\n", c[0]);
    *(pc+1) = 'B';
    printf("Valor del segundo elemento en c: %c\n", c[1]);
    *(pc + 2) = 'C';
    printf("Valor del tercer elemento en c: %c\n", c[2]);
    pc ++;
}