#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    printf("Cuántas estaturas vas a pedir? ");
    scanf("%d", &n);
    int* estaturas = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int temp;
        printf("Escribe una altura: ");
        scanf("%d", &temp);
        estaturas[i] = temp;
    }

    printf("Cuántas mas? ");
    scanf("%d", &m);

    estaturas = (int*) realloc(estaturas, (m+n) * sizeof(int));

    for (int i = n; i < (n+m); i++)
    {
        int temp;
        printf("Escribe una altura: ");
        scanf("%d", &temp);
        estaturas[i] = temp;
    }

    return 0;
}
