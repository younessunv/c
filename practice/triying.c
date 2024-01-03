#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct Departement
{
    char name[33];
};

struct Modules
{
    char name[33];
    char Time_Table[50];
    char Teacher[67];
};

struct Formation
{
    char name[33];
    struct Modules modules[10];
    int moduleCount;
};

void create_Formation(struct Formation *formation);
void save_Formation(const struct Formation *formation);
void search_formation(const char *formation_name);


int main()
{
    int formation_menu_choice;

    char *menu = "1- Create formation\n"
                 "2- Look for formation\n"
                 "3- Exit\n";

    struct Formation formation;

    do
    {
        printf("%s", menu);
        scanf("%d", &formation_menu_choice);
        system("cls");

        if (formation_menu_choice == 1)
        {
            create_Formation(&formation);
            save_Formation(&formation);
            system("pause");
            system("cls");
        }
        else if (formation_menu_choice == 2)
        {
            char formation_name[33];
            printf("Enter the name of the Formation your looking for: ");
            scanf("%s", formation_name);
            system("cls");

            search_formation(formation_name);
            system("pause");
            system("cls");
        }
        else if (formation_menu_choice == 3)
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

void create_Formation(struct Formation *formation)
{
    printf("Name the formation: ");
    scanf("%s", formation->name);

    formation->moduleCount = 0;
    system("cls");
    printf("-------------------------------------- %s: --------------------------------------\n", formation->name);

    while (formation->moduleCount < 10) 
    {
        printf("\nEnter details for Module %d:\n", formation->moduleCount + 1);
        printf("Name of the module: ");
        scanf("%s", formation->modules[formation->moduleCount].name);

        printf("Time table: ");
        scanf("%s", formation->modules[formation->moduleCount].Time_Table);

        printf("Teacher: ");
        scanf("%s", formation->modules[formation->moduleCount].Teacher);

        printf("-----------------------------------------------------------\n");

        formation->moduleCount++;

        printf("Do you want to add another module? (1 for Yes, 0 for No): ");
        int addAnother;
        scanf("%d", &addAnother);

        system("cls");
        printf("-------------------------------------- %s: --------------------------------------\n", formation->name);

        if (addAnother != 1) {
            system("cls");
            break; 
        }
    }
}

void save_Formation(const struct Formation *formation)
{
    FILE *file = fopen("formation.txt", "a");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    fprintf(file, "////////////////////////////////////// Formation Name: %s //////////////////////////////////////////\n\n", formation->name);

    for (int i = 0; i < formation->moduleCount; i++)
    {
        fprintf(file, "------------------------Module %d-------------------------\n", i + 1);
        fprintf(file, "Module Name: %s\n", formation->modules[i].name);
        fprintf(file, "Time Table: %s\n", formation->modules[i].Time_Table);
        fprintf(file, "Teacher: %s\n", formation->modules[i].Teacher);
        fprintf(file, "-------------------------------------------------------\n\n");

    }


    fclose(file);
    printf("Information saved to file successfully.\n");
}

void search_formation(const char *formation_name)
{
    FILE *file = fopen("formation.txt", "r");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    char line[100];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strstr(line, "Formation Name: ") != NULL)
        {
            char buffer[33];
            sscanf(line, "////////////////////////////////////// Formation Name: %s //////////////////////////////////////////", buffer);
            if (strcmp(formation_name, buffer) == 0)
            {
                found = 1;
                printf("%s", line); // Print the formation name line
                while (fgets(line, sizeof(line), file) != NULL && !strstr(line, "////////////////"))
                {
                    printf("%s", line); // Print each line after the formation name line until the next formation
                }
                break; // Break out of the loop once the modules for the found formation are printed
            }
        }
    }

    fclose(file);
    if (!found)
    {
        printf("No Formation with that name is found\n");
    }
}
