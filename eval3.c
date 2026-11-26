#include <string.h>
#include <stdio.h>
#include "data_structures/List.h"
#include "data_structures/PriorityQueue.h"
#include "data_structures/Set.h"
#include "data_structures/Map.h"

int compare_ints(Type t1, Type t2)
{
    int* i1 = (int*) t1;
    int* i2 = (int*) t2;

    return *i1 - *i2;
}

void print_int(Type t)
{
    int *i = (int*) t;
    printf("%d", *i);
}

int hash_char(Type key)
{
    return (unsigned char) *(char*) key;
}

Bool equals_char(Type a, Type b)
{
    return *(char*)a == *(char*)b;
}

// Función creada por Daniel J. Bernstein (djb2)
int hash_string(Type key)
{
    unsigned long h = 5381;
    for (char* s = (char*) key; *s != '\0'; s++)
    {
        h = h * 33 + (unsigned char) *s;
    }
    return (int) (h & 0x7fffffff);
}

Bool equals_string(Type a, Type b)
{
    return strcmp((char*)a , (char*)b) == 0 ? True : False;
}

int* firstKDistinct(int* nums, int N, int K)
{
    Set s1 = set_create(compare_ints, NULL, NULL);
    PQueue pq = pqueue_create(N, compare_ints);

    for (int i = 0; i < N; i++)
    {
        if (set_insert(s1, nums+i))
        {
            pqueue_offer(pq, nums+i);
        }
    }

    int* res = NULL;
    if (pqueue_size(pq) >= K)
    {
        res = (int*) malloc(K * sizeof(int));
        for (int i = 0; i < K; i++)
        {
            res[i] = *(int*)pqueue_poll(pq);
        }
    }

    return res;
}

Bool wordPattern(char* P, char** words, int N)
{
    Map letter_to_word = map_create(101, hash_char, equals_char);
    Map word_to_letter = map_create(101, hash_string, equals_string);
    Bool flag = True;

    for (int i = 0; i < N && flag; i++)
    {
        char* letter = P + i;
        char* word = words[i];

        if (map_contains(letter_to_word, letter))
        {
            if (strcmp((char*) map_get(letter_to_word, letter), word) != 0) flag = False;
        } else if (map_contains(word_to_letter, word))
        {
            flag = False;
        } else
        {
            map_put(letter_to_word, letter, word);
            map_put(word_to_letter, word, letter);
        }
    }
    return flag;
}

int main()
{
    printf("=== RETO 1 ===\n");
    int arr[] = {1,2,3,4,5,6,7,8,9};
    List l1 = list_create(NULL);

    for (int i = 0; i < 9; i++)
    {
        list_add(l1, arr+i);
    }
    Iterator ite1 = list_begin(l1);
    while(list_hasNext(ite1))
    {
        ite1 = list_next(ite1);
        int* val = list_data(ite1);
        if (*val % 2 == 0)
        {
            ite1 = list_delete(ite1, l1);
        } else
        {
            int* i = (int*) malloc(sizeof(int));
            *i = *val + 100;
            ite1 = list_insert(ite1, i, l1);
        }
    }

    ite1 = list_begin(l1);
    while(list_hasNext(ite1))
    {
        ite1 = list_next(ite1);
        int* value = list_data(ite1);
        printf("%d", *value);
        printf(list_hasNext(ite1) ? ", ": "\n");
    }
    printf("Final Size -> %zu\n", list_size(l1));

    printf("=== RETO 2 ===\n");

    int arr2[] = {7,1,9,4,8,2,5,8,4,3}; // 10 values
    Set s1 = set_create(compare_ints, print_int, NULL);
    for (int i = 0; i < 10; i++)
    {
        Bool flag = set_insert(s1, arr2 + i);
        printf("Insert? %s\n", flag ? "Yes" : "No");
    }

    set_print(s1);

    int test2[] = {7,1,9,4,8,2,5,8,4,3,11,12};
    for (int i = 0; i < 12; i++)
    {
        printf("Level of %d -> %d\n", *(test2 + i), set_level(s1, test2 + i));
    }

    printf("=== RETO 3 === \n");
    int arr3[] = {1,3,1,2,3,1,4,2,1,6,-1,5,4,1,2,3,0};
    int N = sizeof(arr3) / sizeof(int);
    int K = 4;
    int* result = firstKDistinct(arr3, N, K);
    for (int i = 0; i < K; i++)
    {
        printf("%d ", *(int*)result+i);
    }
    printf("\n");
    printf("=== RETO 4 ===\n");
    char* words1[] = {"dog", "cat", "cat", "dog"};
    char* words2[] = {"dog", "cat", "cat", "fish"};
    char* words3[] = {"dog", "dog", "dog", "dog"};
    char* words4[] = {"aa", "aa", "aa"};

    printf("%s\n", wordPattern("abba", words1, 4) ? "True" : "False"); // True
    printf("%s\n", wordPattern("abba", words2, 4) ? "True" : "False"); // False
    printf("%s\n", wordPattern("abbc", words2, 4) ? "True" : "False"); // True
    printf("%s\n", wordPattern("abbc", words1, 4) ? "True" : "False"); // False
    printf("%s\n", wordPattern("aaaa", words3, 4) ? "True" : "False"); // True
    printf("%s\n", wordPattern("aaaa", words1, 4) ? "True" : "False"); // False
    printf("%s\n", wordPattern("xxx", words4, 3) ? "True" : "False"); // True

    return 0;
}