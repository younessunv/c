int main()
{
    int menu_choice, search_choice;

    char *menu = "1- Save your info\n"
                 "2- Look for some one\n"
                 "3- Exit\n";

    char *search = "1- Search by name\n"
                   "2- Search by age\n"
                   "3- Search by city\n"
                   "4- Search by formation\n"
                   "5- Return\n";

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
            do{

                printf("%s", search);
                scanf("%d", &search_choice);
                system("cls");

                if(search_choice == 1)
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

                else if(search_choice == 2)
                {
                    int age;
                    printf("insert the age of Etudiant looking for: ");
                    scanf("%d", &age);
                    system("cls");

                    check_Etudiant_Info_by_age(age);
                    system("pause");
                    system("cls");
                }

                else if(search_choice == 3)
                {



                }

                else if(search_choice == 4)
                {


                }

                else if(search_choice == 5)
                {
                    break;
                }
                
                else
                {
                    printf("Invalid choice. Please enter 1, 2, 3, 4 or 5.\n\n");
                }

            }while (1);
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
