#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Chack.h"
#include <stdint.h>
#include "data_structures/Queue.h"
#define ALPHABET 26

typedef struct
{
    int id;
    int steps;
} Task;

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

Bool isBalanced(char filename[])
{
    FILE* f1 = fopen(filename, "r");
    if (!f1)
    {
        printf("File could not be opened");
        return False;
    } else
    {
        Chack k = chack_create(1024);
        Bool balanced = True;
        int c;

        while (balanced && (c = fgetc(f1)) != EOF)
        {
            switch(c)
            {
                case '(': case '[': case '{': case '<':
                    chack_push(k, (char)c);
                    break;

                case ')':
                    if (chack_isEmpty(k) || chack_pop(k) != '(') balanced = False;
                    break;
                case ']':
                    if (chack_isEmpty(k) || chack_pop(k) != '[') balanced = False;
                    break;
                case '}':
                    if (chack_isEmpty(k) || chack_pop(k) != '{') balanced = False;
                    break;
                case '>':
                    if (chack_isEmpty(k) || chack_pop(k) != '<') balanced = False;
                    break;

                default:
                    break;
            }
        }

        if (!chack_isEmpty(k)) balanced = False;

        chack_destroy(k);
        fclose(f1);
        return balanced;
    }
}

Queue createTaskQueue(char* filename)
{
    FILE* f1 = fopen(filename, "rb");
    if (!f1) return NULL;

    Queue q = queue_create();

    uint16_t pair[2];

    while (fread(pair, sizeof(uint16_t), 2, f1) == 2)
    {
        Task* tmp = (Task*) malloc(sizeof(Task));
        tmp->id = pair[0];
        tmp->steps = pair[1];
        queue_offer(tmp, q);
    }

    fclose(f1);
    return q;
}

void processTaskQueue(Queue q, char* log_file_name)
{
    FILE* log = fopen(log_file_name, "w");
    if (!log) return;

    int n = 1;
    while(!queue_isEmpty(q))
    {
        Task* t = (Task*) queue_poll(q);
        t->steps--;
        fprintf(log, "%d) Active Task: %d, remaining steps: %d\n", n++, t->id, t->steps);

        if (t->steps > 0) queue_offer(t, q);
        else free(t);
    }

    fclose(log);
}

int main()
{
    printf("=== RETO 1 ===\n");
    char*** matrix = NULL;
    unsigned int* counts = NULL;
    char* words[] = {"int", "main", "double", "char", "else", "long", "case", "for", "while", "continue", "if", "float", "do", "break", "switch"};
    char* words2[] = {"and", "await", "def", "from", "none", "return", "try", "true", "or", "not", "is", "lambda", "global", "except", "else"};
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

    printf("\n\n");

    char*** matrix2 = NULL; unsigned int* counts2 = NULL;
    create_matrix(&matrix2, &counts2, words2, n);

    for (int i = 0; i < ALPHABET; i++)
    {
        if (counts2[i] == 0) continue;
        for (int j = 0; j < counts2[i]; j++)
        {
            printf("%s ", matrix2[i][j]);
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

    printf("\n\n");
    Chack k2 = chack_create(5);
    chack_print(k2);
    for (char c = 'A'; c <= 'Z'; c++) chack_push(k2, c);
    printf("Pop: %c\n", chack_pop(k2));
    printf("Top: %c\n", chack_top(k2));
    chack_print(k2);
    chack_clear(k2);
    chack_print(k2);

    printf("=== RETO 3 ===\n");
    printf("%d\n", isBalanced("test_file.c"));
    printf("%d\n", isBalanced("test_file2.c"));

    printf("=== RETO 4 ===\n");
    Queue q = createTaskQueue("Tasks.dat");
    int tasks = queue_size(q); printf("%d\n", tasks);
    processTaskQueue(q, "log.txt");
}