#include <stdio.h>

int main()
{
    float f = 1.234;
    float* pf = &f;
    (*pf) ++;
    printf("%f\n", f);
    printf("%f\n", *pf);
    printf("%p\n", pf);
    printf("%p\n", &pf);
}