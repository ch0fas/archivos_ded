#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Chack.h"
#define ALPHABET 26

void create_matrix(char**** matrix, unsigned int** counts, char* words[], int N)
{
    *counts = calloc(ALPHABET, sizeof(unsigned int));

    *matrix = calloc(ALPHABET, sizeof(char**));

    for (unsigned int i = 0; i < N; i++)
    {
        unsigned int row = words[i][0] - 'a';
        (*counts)[row]++;
    }

    for (unsigned int i = 0; i < ALPHABET; i++)
    {
        if ((*counts)[i] > 0)
        {
            (*matrix)[i] = calloc((*counts)[i], sizeof(char*));
        }
    }

    unsigned int* pos = calloc(ALPHABET, sizeof(unsigned int));

    for (unsigned int i = 0; i < N; i++)
    {
         unsigned int row = words[i][0] - 'a';
         unsigned int col = pos[row]++;

        (*matrix)[row][col] = malloc(strlen(words[i])+1);

        strcpy((*matrix)[row][col], words[i]);
    }

    free(pos);
}

int main()
{
    printf("=== RETO 1 ===\n");
    char*** matrix = NULL;
    unsigned int* counts = NULL;
    char* words[] = {"int", "main", "double", "char", "else", "long", "case", "for", "while", "continue", "if", "float", "do", "break", "switch"};
    int n = 15;

    create_matrix(&matrix, &counts, words, n);

    for (int i = 0; i < ALPHABET; i++)
    {
        if (counts[i] == 0) continue;
        for (int j = 0; j < counts[i]; j++)
        {
            printf("%s ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("=== RETO 2 ===\n");
    Chack k = chack_create(10);
    chack_print(k);
    for (char c = 'a'; c <= 'z'; c++) chack_push(k, c);
    printf("Pop: %c\n", chack_pop(k));
    printf("Top: %c\n", chack_top(k));
    chack_print(k);
    chack_clear(k);
    chack_print(k);
}