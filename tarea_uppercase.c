#include <stdio.h>

void to_lower_case_v1(char words[][10], int n) // Version 1, notación de apuntadores
{
    char* ptr = *words;
    for (int i = 0; i < n; i++)
    {
        char* letter_ptr = ptr;
        while (*letter_ptr != '\0')
        {
            if (*letter_ptr >= 65 && *letter_ptr <= 90)
            {
                *letter_ptr += 32;
            }
            letter_ptr++;
        }
        ptr+= 10;
    }
}

void to_lower_case_v2(char words[][10], int n) // Version 2, notación de arreglos
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (words[i][j] != '\0' && words[i][j] >= 65 && words[i][j] <= 90)
            {
                words[i][j] += 32;
            }
        }
    }
}

int main()
{
    char arr[][10] = {"HOLA", "MUNDO", "Cruel5", "ADIOS"};
    char arr2[][10] = {"HOLA", "MUNDO", "Cruel5", "ADIOS"};
    to_lower_case_v1(arr, 4);
    to_lower_case_v2(arr2, 4);
    printf("Usando la v1: %s %s %s %s\n", arr[0], arr[1], arr[2], arr[3]);
    printf("Usando la v2: %s %s %s %s\n", arr2[0], arr2[1], arr2[2], arr2[3]);
    return 0;
}