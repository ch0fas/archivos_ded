#include <stdio.h>

typedef enum
{
    False,
    True
} boolean;

int my_len(char* arr)
{
    int res = 0;
    while (arr[res] != '\0')
    {
        res++;
    }

    /* Otras formas de hacer el while loop
     * while (*(string + res) != '\0') { res++; }
     */
    return res;
}

boolean equals(char* s1, char* s2)
{
    if (my_len(s1) != my_len(s2))
    {
        return False;
    }
    char* p1 = s1;
    char* p2 = s2;
    while (*p1 != '\0')
    {
        if (*p1 != *p2)
        {
            return False;
        }
        p1++;
        p2++;
    }
    return True;
}

int main()
{
    char* s1 = "Hola";
    char* s2 = "Holaa";
    int result = equals(s1, s2);
    if (result == 0)
    {
        printf("Son distintos\n");
    } else printf("Son iguales\n");
}
