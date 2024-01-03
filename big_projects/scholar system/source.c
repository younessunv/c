#include <stdio.h>
#include <stdlib.h>
#include "Etudiant.h"
#include "Teacher.h"
#include "Departement.h"
#include "Formation.h"
#include "Modules.h"


int main()
{
    int menu_choice;

    char *Menu = "1- Etudiant\n"
                 "2- Teacher\n"
                 "3- Departement\n"
                 "4- Formation\n"
                 "5- Exit\n";

    do
    {
        printf("%s", Menu);
        scanf("%d", &menu_choice);
        system("cls");

        if(menu_choice == 1)
        {
            Etudiant_menu();
        }

        else if(menu_choice == 2)
        {
            Teacher_Menu();
        }

        else if(menu_choice == 3)
        {
            Departement_menu();
        }

        else if(menu_choice == 4)
        {
            Formation_menu();
        }

        else if(menu_choice == 5)
        {
            break;
        }

        else
        {
            printf("Invalid choice. Please enter 1, 2, 3, 4 or 5.\n\n");
        }

    } while (1);


    return 0;
}