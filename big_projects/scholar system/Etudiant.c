#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Etudiant.h"


void Etudiant_menu()
{
    int etudiant_menu_choice;

    char *etudiant_menu = "1- Save your info\n"
                 "2- Look for some one\n"
                 "3- Return\n";

    struct Etudiant Etudiant;

    do
    {
        printf("%s", etudiant_menu);
        scanf("%d", &etudiant_menu_choice);
        system("cls");

        if (etudiant_menu_choice == 1)
        {
            int EtudiantCount = read_Etudiant_Count();
            get_Etudiant_Info(&Etudiant);
            EtudiantCount++;
            adding_Etudiant_info(&Etudiant, EtudiantCount);
            write_etudiant_Count(EtudiantCount);
            system("pause");
            system("cls");
        }

        else if (etudiant_menu_choice == 2)
        {
            Etudiant_Search();
        }

        else if (etudiant_menu_choice == 3)
        {
            break;
        }

        else
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n\n");
        }

    } while (1);

}

void get_Etudiant_Info(struct Etudiant *Etudiant)
{

    printf("Enter your First name: ");
    scanf("%32s", Etudiant->Etudiant_First_name);
    clearInputBuffer();

    printf("Enter your Last name: ");
    scanf("%32s", Etudiant->Etudiant_last_name);
    clearInputBuffer();

    printf("Enter your age: ");
    scanf("%d", &Etudiant->Etudiant_age);
    clearInputBuffer();

    printf("Enter your city: ");
    scanf("%32s", Etudiant->Etudiant_city);
    clearInputBuffer();

    printf("Enter your formation: ");
    scanf("%32s", Etudiant->Etudiant_formation);
    clearInputBuffer();

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
    int count = 0;
    FILE *countFile = fopen("EtudiantCount.txt", "r");

    if (countFile == NULL)
    {
        // File doesn't exist, create and initialize with 0
        countFile = fopen("EtudiantCount.txt", "w");
        if (countFile != NULL)
        {
            fprintf(countFile, "0");
            fclose(countFile);
        }
        else
        {
            perror("Error creating and initializing EtudiantCount.txt");
            return 0;
        }
    }
    else
    {
        // File exists, read the count
        if (fscanf(countFile, "%d", &count) != 1)
        {
            count = 0;
        }
        fclose(countFile);
    }

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

void Etudiant_Search()
{
    int Etudiant_search_choice;

    char *Etudiant_search = "1- Search by name\n"
                   "2- Search by age\n"
                   "3- Search by city\n"
                   "4- Search by formation\n"
                   "5- Return\n";

    do
    {

        printf("%s", Etudiant_search);
        scanf("%d", &Etudiant_search_choice);
        system("cls");

        if (Etudiant_search_choice == 1)
        {

            char First_name[33], Last_name[33];
            printf("insert the first name of the Etudiant your looking for: ");
            scanf("%32s", First_name);
            printf("Last name: ");
            scanf("%32s", Last_name);
            system("cls");

            check_Etudiant_Info_by_name(First_name, Last_name);
            system("pause");
            system("cls");
        }

        else if (Etudiant_search_choice == 2)
        {
            int age;
            printf("insert the age of Etudiant looking for: ");
            scanf("%d", &age);
            system("cls");

            check_Etudiant_Info_by_age(age);
            system("pause");
            system("cls");
        }

        else if (Etudiant_search_choice == 3)
        {
            char city[50];
            printf("insert the City of the Etudiant your looking for: ");
            scanf("%32s", city);
            system("cls");

            check_Etudiant_Info_by_city(city);
            system("pause");
            system("cls");
        }

        else if (Etudiant_search_choice == 4)
        {
            char formation[33];
            printf("insert the Formation of the Etudiant your looking for: ");
            scanf("%32s", formation);
            system("cls");

            check_Etudiant_Info_by_formation(formation);
            system("pause");
            system("cls");
        }

        else if (Etudiant_search_choice == 5)
        {
            break;
        }

        else
        {
            printf("Invalid choice. Please enter 1, 2, 3, 4 or 5.\n\n");
        }

    } while (1);
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
        char first_Name[33], last_Name[33], previous_line[33];

        if (strstr(line, "First Name: ") != NULL)
        {
            sscanf(line, "First Name: %s", first_Name);
            if (strstr(first_Name, firstName) != NULL)
            {
                strcpy(previous_line, line);
                fgets(line, sizeof(line), file);

                if (strstr(line, "Last Name: ") != NULL)
                {
                    sscanf(line, "Last Name: %s", last_Name);
                    if (strstr(last_Name, lastName) != NULL)
                    {
                        printf("%s", previous_line);
                        printf("%s", line);
                        found = 1;

                        for (int i = 0; i < 3; i++)
                        {
                            fgets(line, sizeof(line), file);
                            printf("%s", line);
                        }
                    }
                }
            }
        }
    }

    fclose(file);

    if (!found)
    {
        system("cls");
        printf("Etudiant not found.\n");
    }
}

void check_Etudiant_Info_by_age(const int age)
{
    FILE *file = fopen("Etudiant.txt", "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    int count = 0;
    char line[33];
    int found = 0;
    char buffer[3][33];

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "Age: ") != NULL)
        {
            int etudiantAge;
            sscanf(line, "Age: %d", &etudiantAge);

            if (etudiantAge == age)
            {
                count++;
                found = 1;
            }
        }
    }

    fclose(file);

    if (found)
    {
        printf("----------------------Found %d Etudiant(s) with the specified Age-----------------------\n\n", count);

        file = fopen("Etudiant.txt", "r");
        if (file == NULL)
        {
            perror("Error opening file");
            return;
        }

        while (fgets(line, sizeof(line), file))
        {
            // Shift lines in the buffer
            strcpy(buffer[0], buffer[1]);
            strcpy(buffer[1], buffer[2]);
            strcpy(buffer[2], line);

            if (strstr(line, "Age: ") != NULL)
            {
                int etudiantAge;
                sscanf(line, "Age: %d", &etudiantAge);

                if (etudiantAge == age)
                {
                    // Print the 2 lines before Age, Age line, and 1 line after Age
                    for (int i = 0; i < 3; i++)
                        printf("%s", buffer[i]);

                    for (int i = 0; i < 2; i++)
                    {
                        fgets(line, sizeof(line), file); // Read and print the next line after Age
                        printf("%s", line);
                    }
                    printf("---------------------------------------\n\n");
                }
            }
        }

        fclose(file);
    }
    else
    {
        system("cls");
        printf("No Etudiant found with the specified age.\n");
    }
}

void check_Etudiant_Info_by_city(const char *city)
{
    FILE *file = fopen("Etudiant.txt", "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    int count = 0;
    char line[33];
    int found = 0;
    char buffer[4][33];

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "City: ") != NULL)
        {
            sscanf(line, "City: %s", buffer[3]);

            if (strstr(city, buffer[3]) != NULL)
            {
                count++;
                found = 1;
            }
        }
    }

    fclose(file);

    if (found)
    {
        printf("----------------------Found %d Etudiant(s) with the specified City-----------------------\n\n", count);

        file = fopen("Etudiant.txt", "r");
        if (file == NULL)
        {
            perror("Error opening file");
            return;
        }

        while (fgets(line, sizeof(line), file))
        {
            // Shift lines in the buffer
            strcpy(buffer[0], buffer[1]);
            strcpy(buffer[1], buffer[2]);
            strcpy(buffer[2], buffer[3]);
            strcpy(buffer[3], line);

            if (strstr(line, "City: ") != NULL)
            {
                sscanf(line, "City: %s", buffer[3]);

                if (strstr(city, buffer[3]) != NULL)
                {
                    for (int i = 0; i < 3; i++)
                        printf("%s", buffer[i]);

                    printf("%s", line); // Print the line containing the City

                    fgets(line, sizeof(line), file);
                    printf("%s", line);

                    printf("---------------------------------------\n\n");
                }
            }
        }

        fclose(file);
    }
    else
    {
        system("cls");
        printf("No Etudiant found with the specified city.\n");
    }
}

void check_Etudiant_Info_by_formation(const char *formation)
{
    FILE *file = fopen("Etudiant.txt", "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    int count = 0;
    char line[33];
    int found = 0;
    char buffer[5][33];

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "Formation: ") != NULL)
        {
            sscanf(line, "Formation: %s", buffer[4]);

            if (strstr(formation, buffer[4]) != NULL)
            {
                count++;
                found = 1;
            }
        }
    }

    fclose(file);

    if (found)
    {
        printf("----------------------Found %d Etudiant(s) with the specified Formation-----------------------\n\n", count);

        file = fopen("Etudiant.txt", "r");
        if (file == NULL)
        {
            perror("Error opening file");
            return;
        }

        while (fgets(line, sizeof(line), file))
        {
            // Shift lines in the buffer
            strcpy(buffer[0], buffer[1]);
            strcpy(buffer[1], buffer[2]);
            strcpy(buffer[2], buffer[3]);
            strcpy(buffer[3], buffer[4]);
            strcpy(buffer[4], line);

            if (strstr(line, "Formation: ") != NULL)
            {
                sscanf(line, "Formation: %s", buffer[4]);

                if (strstr(formation, buffer[4]) != NULL)
                {
                    for (int i = 0; i < 4; i++)
                        printf("%s", buffer[i]);

                    printf("%s", line);

                    printf("---------------------------------------\n\n");
                }
            }
        }

        fclose(file);
    }
    else
    {
        system("cls");
        printf("No Etudiant found with the specified city.\n");
    }
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}