#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {SENT, DELIVERED, FAILED} Status;
typedef struct
{
    char text[50];
    Status status;
    char sender[20];
    int destinationCount;
    char* destination[20];
} Message;
typedef enum {FALSE, TRUE} Bool;

typedef Bool(*FilterFunc)(Message*, void*);

void countMessages(Message messages[], int N, char* username, int* sent, int* received)
{
    Message* mp = messages;
    for (int i = 0; i < N; i++)
    {
        if (mp->status == SENT && (strcmp(username, mp->sender) == 0)) (*sent)++;
        if (mp->status == DELIVERED)
        {
            char** recipient_pointer = mp->destination;
            for (int j = 0; j < mp->destinationCount; j++)
            {
                if (strcmp(username, *recipient_pointer) == 0) (*received)++;
                recipient_pointer++;
            }
        }
        mp++;
    }
}

Bool isFailedMessage(Message* message, void* data)
{
    return message->status == FAILED;
}

Bool isMessageFrom(Message* message, void* data)
{
    char* sender = (char*) data;
    return strcmp(message->sender, sender) == 0;
}

Message* filterMessages(Message* messages[], int N, FilterFunc filter, void* data, int* total_messages)
{
    Message* res = (Message*) malloc(N * sizeof(Message));
    Message* rp = res;
    Message** mp = messages;
    for (int i = 0; i < N; i++)
    {
        if (filter(*mp, data) == 1)
        {
            *rp = **mp;
            (*total_messages)++;
            rp++;
        }
        mp++;
    }

    return res;
}

void count_vowels(char words[][30], int count[], int N)
{
    char (*word_ptr)[30] = words;
    for (int i = 0; i < N; i++)
    {
        char* cptr = *word_ptr;
        while (*cptr != '\0')
        {
            if (*cptr == 'A' || *cptr == 'a') (*count)++;
            if (*cptr == 'E' || *cptr == 'e') (*(count + 1))++;
            if (*cptr == 'I' || *cptr == 'i') (*(count + 2))++;
            if (*cptr == 'O' || *cptr == 'o') (*(count + 3))++;
            if (*cptr == 'U' || *cptr == 'u') (*(count + 4))++;
            cptr++;
        }
        word_ptr++;
    }
}

int main()
{
    printf("=== RETO 1 y 2 ===\n");
    Message messages[10] =
    {
        {"Buenas tardes", SENT, "sofia", 2, {"viviana", "denise"}}, // Va a salir
        {"Hola!", SENT, "viviana", 1, "sofia"},
        {"Mucho Gusto!", SENT, "denise", 1, "viviana"},
        {"Mensaje fallido rip", FAILED, "sofia", 1, "denise"},
        {"Mensaje exitoso yay", DELIVERED, "denise", 2, "viviana", "sofia"}, // Va a salir, porque es Status DELIVERED y lo recibo yo
        {"Print foo", DELIVERED, "sofia", 1, {"sofia"}}, // Raro pero también debería aparecer
        {"La tarea es...", FAILED, "denise", 1, "sofia"},
        {"Mañana hacemos la tarea juntas?", SENT, "sofia", 1, {"viviana"}}, // Va a salir
        {"OK!", DELIVERED, "viviana", 1, {"sofia"}}, // Va a salir
        {"Yay!", SENT, "sofia", 1, {"viviana"}} // Va a salir
    };

    int sent = 0;
    int received = 0;
    countMessages(messages, 10, "sofia", &sent, &received);
    printf("Mensajes Enviados por %s: %d\nMensajes recibidos por %s: %d\n", "sofia", sent, "sofia", received); // Deberían ser 3 y 3 respectivamente

    printf("=== RETO 3 ===\n");
    // Definiciones de funciones y tipo de dato arriba
    FilterFunc ff1 = isFailedMessage;
    FilterFunc ff2 = isMessageFrom;
    printf("%d\n", ff1(messages, "foo")); // Debería dar 0, porque el primer mensaje no es fallido
    printf("%d\n", ff2(messages, "sofia")); // Debería dar 1, porque el primer mensaje viene de sofía

    printf("=== Reto 4 y 5 ===\n");
    Message* messages2[10] =
    {
        &messages[0], &messages[1], &messages[2], &messages[3], &messages[4], &messages[5], &messages[6], &messages[7], &messages[8], &messages[9]
    }; // Para simplificar, se re-utilizan los mensajes del primer arreglo

    int message_total = 0;
    Message* new_messages = filterMessages(messages2, 10, ff2, "sofia", &message_total); // El arreglo final debería tener 5 mensajes
    printf("Mensajes que pasaron el filtro: %d\n", message_total);
    for (int i = 0; i < message_total; i++)
    {
        printf("Mensaje %d: %s\n", (i+1), new_messages[i].text); // Verificando que los mensajes que pasan el filtro sean los correctos
    }

    printf("=== RETO 6 ===\n");
    char words[][30] = {"Apuntadores", "Funciones", "Estructuras"};
    int count[5] = {0};
    count_vowels(words, count, 3);
    printf("A=%d\nE=%d\nI=%d\nO=%d\nU=%d\n", count[0], count[1], count[2], count[3], count[4]);

    return 0;
}