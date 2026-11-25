#include <stdio.h>
#include <stdlib.h>
#include "data_structures/Stack.h"
#include "data_structures/Queue.h"

char* undo(char letters[])
{
    Stack s1 = stack_create();
    while (*letters != '\0')
    {
        if (*letters != '*')
        {
            stack_push((void*)letters, s1);
        } else
        {
            stack_pop(s1);
        }
        letters++;
    }
    char* res = (char*) calloc(stack_size(s1) + 1, sizeof(char));
    res[stack_size(s1)] = '\0';
    for (int i = stack_size(s1)-1; i >= 0; i--)
    {
        res[i] = *(char*)stack_pop(s1);
    }
    return res;
}

void process_tasks(int d[], int N)
{
    Queue q1 = queue_create();
    int* remainings = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        remainings[i] = d[i];
        int* ip = (int*) malloc(sizeof(int));
        *ip = i;
        queue_offer(ip, q1);
    }
    while (!queue_isEmpty(q1))
    {
        int* id = (int*) queue_poll(q1);
        printf("%d", *id+1);
        remainings[*id]--;
        if (remainings[*id] > 0)
        {
            queue_offer(id, q1);
        }
    }
    printf("\n");
}

int main()
{
    char* str1 = "abcde****";
    printf("%s", undo(str1));
    int durations[] = {5,2,3,1,4};
    process_tasks(durations, 5);
    return 0;
}
