#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Etudiant.h"

int main()
{
    int menu_choice;

    char *menu = "1- Save your info\n"
                 "2- Look for some one\n"
                 "3- Exit\n";

    struct Etudiant Etudiant;

    do
    {
        printf("%s", menu);
        scanf("%d", &menu_choice);
        system("cls");

        if (menu_choice == 1)
        {
            int EtudiantCount = read_Etudiant_Count();
            get_Etudiant_Info(&Etudiant);
            EtudiantCount++;
            adding_Etudiant_info(&Etudiant, EtudiantCount);
            write_etudiant_Count(EtudiantCount);
            system("pause");
            system("cls");
        }

        else if (menu_choice == 2)
        {
            Search();
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

    return 0;
}