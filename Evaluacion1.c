//Autores: Vanesa Rivera, Mariano Sanchez
//Fecha: 21/ 09/ 2026
//EVALUACION 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {SENT, DELIVERED, FAILED} Status;

typedef enum {FALSE, TRUE} Bool;

typedef struct {
    char text[50];
    Status status;
    char sender[20];
    int destinationCount;
    char *destination[20];
} Message;

// RETO 1
void countMessages(Message *messages, int N, char *username, int *sent, int *received) {

    int i, j;
    *sent = 0;
    *received = 0;

    for (i = 0; i < N; i++) {
        if ((messages + i)->status == DELIVERED &&
            strcmp((messages + i)->sender, username) == 0) {
            (*sent)++;
        }

        if ((messages + i)->status == DELIVERED) {
            for (j = 0; j < (messages + i)->destinationCount; j++) {
                if (strcmp(*((messages + i)->destination + j), username) == 0) {
                    (*received)++;
                    break;
                }
            }
        }
    }
}

// RETO 3
typedef Bool (*FilterFunc)(Message *message, void *data);

Bool isFailedMessage(Message *message, void *data) {
    return message->status == FAILED;
}

Bool isMessageFrom(Message *message, void *data) {
    char *sender = (char *)data;
    return strcmp(message->sender, sender) == 0;
}

// RETO 4
Message** filterMessages(Message **messages, int N, FilterFunc filter, void *data, int *n) {
    *n = 0;
    
    for (int i = 0; i < N; i++) {
        if (filter(messages[i], data) == TRUE) {
            (*n)++;
        }
    }
    
    Message **filteredArray = (Message **)malloc((*n) * sizeof(Message *));
    if (filteredArray == NULL) return NULL; 
    
    int index = 0;
    for (int i = 0; i < N; i++) {
        if (filter(messages[i], data) == TRUE) {
            filteredArray[index++] = messages[i];
        }
    }
    
    return filteredArray;
}

// RETO 6
void countVowels(char words[][30], int N, int *count) {
    for (int i = 0; i < 5; i++) {
        *(count + i) = 0;
    }

    for (int i = 0; i < N; i++) {
        char *ptr = *(words + i); 
        
        while (*ptr != '\0') {
            char c = *ptr;
            if (c == 'a' || c == 'A') (*(count + 0))++;
            else if (c == 'e' || c == 'E') (*(count + 1))++;
            else if (c == 'i' || c == 'I') (*(count + 2))++;
            else if (c == 'o' || c == 'O') (*(count + 3))++;
            else if (c == 'u' || c == 'U') (*(count + 4))++;
            ptr++;
        }
    }
}

int main() {

    // RETO 2
    Message messages[8] = {
        {"Hola Luis", DELIVERED, "Ana", 1, {"Luis"}},
        {"Hola Pedro", DELIVERED, "Ana", 1, {"Pedro"}},
        {"Mensaje fallido", FAILED, "Ana", 1, {"Luis"}},
        {"Hola Ana", DELIVERED, "Luis", 1, {"Ana"}},
        {"Para varios", DELIVERED, "Pedro", 2, {"Ana", "Luis"}},
        {"Otro mensaje", SENT, "Ana", 1, {"Pedro"}},
        {"Mensaje de Juan", DELIVERED, "Juan", 2, {"Pedro", "Ana"}},
        {"Ultimo mensaje", DELIVERED, "Ana", 2, {"Luis", "Juan"}}
    };

    int sent;
    int received;

    countMessages(messages, 8, "Ana", &sent, &received);

    printf("Mensajes enviados exitosamente por Ana: %d\n", sent);
    printf("Mensajes recibidos exitosamente por Ana: %d\n", received);


    // RETO 5
    Message *messagePointers[8];
    for (int i = 0; i < 8; i++) {
        messagePointers[i] = &messages[i];
    }

    int n_filtered = 0;
    char targetSender[] = "Ana";
    
    Message **filteredResult = filterMessages(messagePointers, 8, isMessageFrom, targetSender, &n_filtered);

    printf("\nMensajes filtrados (Enviados por %s): %d encontrados\n", targetSender, n_filtered);
    for (int i = 0; i < n_filtered; i++) {
        printf("- %s [Status: %d]\n", filteredResult[i]->text, filteredResult[i]->status);
    }
    
    free(filteredResult);


    // RETO 6
    char words[][30] = { "Apuntadores", "Funciones", "Estructuras"};
    int count[5];
    int N_words = 3;
    
    countVowels(words, N_words, count);
    
    printf("\nConteo de vocales: {%d, %d, %d, %d, %d}\n", 
            count[0], count[1], count[2], count[3], count[4]);

    return 0;
}