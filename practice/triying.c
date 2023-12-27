#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


struct Etudiant
{
    char Etudiant_First_name[33];
    char Etudiant_last_name[33];
    int Etudiant_age;
    char Etudiant_city[33];
    char Etudiant_formation[33];
};

void get_Etudiant_Info(struct Etudiant *Etudiant);
void adding_Etudiant_info(const struct Etudiant *Etudiant, int personCount);
int read_Etudiant_Count();
void write_etudiant_Count(int count);
void check_Etudiant_Info_by_name(const char *firstName, const char *lastName);
void check_Etudiant_Info_by_age(int age);

int main()
{
    int choice;
    char *menu = "1- Save your info\n"
                 "2- Look for some one\n"
                 "3- Exit\n";

    struct Etudiant Etudiant;

    do
    {
        printf("%s", menu);
        scanf("%d", &choice);
        system("cls");

        if (choice == 1)
        {
            int EtudiantCount = read_Etudiant_Count();
            get_Etudiant_Info(&Etudiant);
            EtudiantCount++;
            adding_Etudiant_info(&Etudiant, EtudiantCount);
            write_etudiant_Count(EtudiantCount);
            system("pause");
            system("cls");
        }

        else if (choice == 2)
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

        else if (choice == 3)
        {
            break;
        }

        else
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n\n");
        }

    } while (1);

    return 0;
}

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
        char first_Name[33], last_Name[33];

        if (strstr(line, "First Name: ") != NULL)
        {
            sscanf(line, "First Name: %s", first_Name);
            if (strstr(first_Name, firstName) != NULL)
            {
                printf("%s", line);
                fgets(line, sizeof(line), file);

                if (strstr(line, "Last Name: ") != NULL)
                {
                    sscanf(line, "Last Name: %s", last_Name);
                    if (strstr(last_Name, lastName) != NULL)
                    {
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


void check_Etudiant_Info_by_age(int age)
{
    FILE *file = fopen("Etudiant.txt", "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[50];
    int found = 0;
    int count = 0;

    while (fgets(line, sizeof(line), file))
    {

        if (strstr(line, "Age: ") != NULL)
        {
            int Etudiant_age;
            sscanf(line, "Age: %d", Etudiant_age);
            if (Etudiant_age == age)
            {
               found = 1;
               count++;
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

