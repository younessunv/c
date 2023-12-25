#include <stdio.h>
#include <stdlib.h>
#include "Etudiant.h"

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
