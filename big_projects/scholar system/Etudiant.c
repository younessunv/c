#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Etudiant.h"

struct Etudiant Etudiant;


void get_Etudiant_Info(struct Etudiant *Etudiant)
{
    printf("Enter your First name: ");
    scanf("%32s", Etudiant->Etudiant_First_name);

    printf("Enter your Last name: ");
    scanf("%32s", Etudiant->Etudiant_last_name);

    printf("Enter your age: ");
    scanf("%d", &Etudiant->Etudiant_age);

    printf("Enter your city: ");
    scanf("%32s", Etudiant->Etudiant_city);

    printf("Enter your formation: ");
    scanf("%32s", Etudiant->Etudiant_formation);
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
    fprintf(file, "First Name: %s\n", Etudiant->Etudiant_First_name);
    fprintf(file, "Last Name: %s\n", Etudiant->Etudiant_last_name);
    fprintf(file, "Age: %d\n", Etudiant->Etudiant_age);
    fprintf(file, "City: %s\n", Etudiant->Etudiant_city);
    fprintf(file, "Formation: %s\n", Etudiant->Etudiant_formation);
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

void check_Etudiant_Info_by_name(const char *firstName, const char *lastName)
{
    FILE *file = fopen("Etudiant.txt", "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[50];
    int found = 0;

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, firstName) != NULL)
        {
            printf("%s", line);
            fgets(line, sizeof(line), file);
            if (strstr(line, lastName) != NULL)
            {
                printf("%s", line);
                for (int i = 0; i < 3; ++i)
                {
                    fgets(line, sizeof(line), file);
                    printf("%s", line);
                }
                found = 1;
                break;
            }
        }
    }

    fclose(file);

    if (!found)
    {
        printf("Etudiant not found.\n");
    }
}
