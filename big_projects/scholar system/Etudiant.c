#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Etudiant.h"

struct Etudiant Etudiant;


void get_Etudiant_Info(struct Etudiant *Etudiant)
{
    printf("Enter your user name: ");
    fgets(Etudiant->user_name, 33, stdin);
    size_t len = strlen(Etudiant->user_name);
    if (len > 0 && Etudiant->user_name[len - 1] == '\n')
        Etudiant->user_name[len - 1] = '\0';

    printf("Enter your age: ");
    scanf("%d", &Etudiant->age);
    getchar();

    printf("Enter your formation: ");
    fgets(Etudiant->formation, 33, stdin);
    len = strlen(Etudiant->formation);
    if (len > 0 && Etudiant->formation[len - 1] == '\n')
        Etudiant->formation[len - 1] = '\0';
}

void adding_Etudiant_info(const struct Etudiant *Etudiant, int EtudiantCount)
{
    FILE *file = fopen("Etudiant.txt", "a");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    fprintf(file, "----------------Etudiant %d----------------\n", EtudiantCount);
    fprintf(file, "User Name: %s\n", Etudiant->user_name);
    fprintf(file, "Age: %d\n", Etudiant->age);
    fprintf(file, "Formation: %s\n", Etudiant->formation);
    fprintf(file, "-----------------------------------------\n");

    fclose(file);
    printf("Information saved to file successfully.\n");
}

int read_Etudiant_Count()
{
    int count;
    FILE *countFile = fopen("EtudiantCount.txt", "r");

    if (countFile == NULL)
    {
        return 0;
    }

    fscanf(countFile, "%d", &count);
    fclose(countFile);

    return count;
}

void write_etudiant_Count(int count)
{
    FILE *countFile = fopen("EtudiantCount.txt", "w");

    if (countFile == NULL)
    {
        perror("Error writing count");
        return;
    }

    fprintf(countFile, "%d", count);
    fclose(countFile);
}

void search_Etudiant_Info(char *textToFind)
{
    FILE *file = fopen("Etudiant.txt", "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error opening file: Etudiant.txt\n");
        return;
    }

    char line[44];
    int found = 0;

    while (fgets(line, 44, file) != NULL)
    {
        if (strstr(line, textToFind) != NULL)
        {
            found = 1;

            printf("\n%s", line);
            for (int i = 0; i < 2; i++)
            {
                if (fgets(line, 44, file) != NULL)
                {
                    printf("%s", line);
                }
            }
        }
    }

    fclose(file);

    if (!found)
    {
        printf("Name does not exist in the file.\nMaybe try to save this Etudiant info in the file.\n");
    }
}
