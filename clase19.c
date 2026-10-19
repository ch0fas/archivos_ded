#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1024

int main()
{
    FILE* f1 = fopen("foo.txt", "r");
    if (!f1)
    {
        printf("File could not be opened\n");
        return 1;
    } else
    {
        printf("File Opened successfully\n");
        char buffer[BUFFER_SIZE];
        char* res;
        while (!feof(f1))
        {
            res = fgets(buffer, BUFFER_SIZE, f1);
            printf("%s", res);
        }
    }
    fclose(f1);

    FILE* f2 = fopen("cities.txt", "w");
    if (!f2)
    {
        printf("Error creating File");
        return 1;
    } else
    {
        char buffer[BUFFER_SIZE];
        strcpy(buffer, "Guadalajara\n");
        fputs(buffer, f2);
        strcpy(buffer, "Auckland\n");
        fputs(buffer, f2);
        strcpy(buffer, "CDMX\n");
        fputs(buffer, f2);
        strcpy(buffer, "New York\n");
        fputs(buffer, f2);
        strcpy(buffer, "Berlin\n");
        fputs(buffer, f2);
    }
    fclose(f2);

    FILE* f3 = fopen("data.txt", "w");
    if (!f3)
    {
        printf("Error creating File");
        return 1;
    } else
    {
        fprintf(f3, "%s\t%s\t%s\t%s\n", "Expediente", "Nombre", "Promedio", "Semestre");
        fprintf(f3, "%d\t%s\t%.1f\t%d\n", 751299, "Sofia", 9.3, 7);
        fprintf(f3, "%d\t%s\t%.1f\t%d\n", 751678, "Vivi", 9.6, 7);
        fprintf(f3, "%d\t%s\t%.1f\t%d\n", 751001, "Mariane", 9.5, 9);
        fprintf(f3, "%d\t%s\t%.1f\t%d\n", 760002, "Connell", 9.5, 9);
    }
    fclose(f3);

    FILE* f4 = fopen("data.txt", "a");
    if (!f4)
    {
        printf("Error Opening File");
        return 1;
    } else
    {
        fprintf(f4, "%d\t%s\t%.1f\t%d\n", 748222, "Elio", 9.0, 3);
    }

    return 0;
}
