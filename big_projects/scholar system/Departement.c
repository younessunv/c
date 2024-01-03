#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Departement.h"

void Departement_menu()
{
    struct Departement departement;

    int menu_choice;

    char *menu = "1- Create Departement\n"
                 "2- Look THe Departments\n"
                 "3- Return\n";

    do
    {
        printf("%s", menu);
        scanf("%d", &menu_choice);
        system("cls");

        if (menu_choice == 1)
        {
            create_Departement(&departement);
            save_Departement(&departement);
            system("pause");
            system("cls");
        }

        else if (menu_choice == 2)
        {
            search_Departement();
            system("pause");
            system("cls");
        }

        else if (menu_choice == 3)
        {
            break;
        }

        else
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n\n");
        }
    } while (1);
    
}

void create_Departement(struct Departement *departement)
{
    totalDepartments++;
    departement->departementCount = totalDepartments;

    printf("What is the name of your Departement: ");
    scanf("%s", departement->name);

}

void save_Departement(const struct Departement *departement)
{
    FILE *file = fopen("departement.txt", "a");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    fprintf(file, "Departement N* %d: %s\n", departement->departementCount, departement->name);

    fclose(file);
    system("cls");
    printf("Information saved to file successfully.\n");
}

void search_Departement()
{
    FILE *file = fopen("departement.txt", "r");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    char line[50];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        found = 1;
        printf("%s", line);
    }

    fclose(file);
    if(!found)
    {
        printf("no content found on the file try insert some departements\n");
    }
}
