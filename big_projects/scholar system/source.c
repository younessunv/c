#include <stdio.h>
#include <stdlib.h>
#include "Etudiant.h"

int main()
{
    int choice;
    char *menu = "1- Save your info\n"
                 "2- Look for someone\n"
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
            char Etudiants_name[33];
            printf("Insert the name of the Etudiant you're looking for: ");
            scanf("%32s", Etudiants_name);
            system("cls");

            search_Etudiant_Info(Etudiants_name);
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
