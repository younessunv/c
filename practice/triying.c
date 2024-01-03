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
/// ////////////////////////////////////////////////////////////////
struct Teacher
{
    char Teacher_First_name[33];
    char Teacher_Last_name[33];
    char Teacher_speciality[33];
};
/////////////////////////////////////////////////////////////////////
struct Departement
{
    char name[33];
    int departementCount;
};

int totalDepartments = 0;
//////////////////////////////////////////////////
struct  Modules
{
    char name[33];
    char Time_Table[50];
    char Teacher[67];
};
////////////////////////////////////////////////////
struct Formation
{
    char name[33];
    struct Modules modules[10];
    int moduleCount;
};


///////////////////////////////////////////////////////////etudiant////////////////////////////
void Etudiant_menu();
void get_Etudiant_Info(struct Etudiant *Etudiant);
void adding_Etudiant_info(const struct Etudiant *Etudiant, int EtudiantCount);
int read_Etudiant_Count();
void write_etudiant_Count(int count);
void Etudiant_Search();
void check_Etudiant_Info_by_name(const char *firstName, const char *lastname);
void check_Etudiant_Info_by_age(const int age);
void check_Etudiant_Info_by_city(const char *city);
void check_Etudiant_Info_by_formation(const char *formation);
void clearInputBuffer();

/////////////////////////////////////////////////////Teacher////////////////////////////////////
void Teacher_Menu();
void get_Teacher_info(struct Teacher *Teacher);
void adding_Teacher_info(const struct Teacher *Teacher, int TeacherCount);
int read_Teacher_Count();
void write_Teacher_Count(int count);
void Teacher_Search();
void check_Teacher_Info_by_name(const char *firstName, const char *lastName);
void check_Teacher_Info_by_speciality(const char *speciality);
//////////////////////////////////////////////////////formation///////////////////////////////////
void Formation_menu();
void create_Formation(struct Formation *formation);
void save_Formation(const struct Formation *formation);
void search_formation(const char *formation_name);
//////////////////////////////////////////////////////Departement/////////////////////////////////////
void Departement_menu();
void create_Departement(struct Departement *departement);
void save_Departement(const struct Departement *departement);
void search_Departement();


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


///////////////////////////////////////////////////////////etudiant////////////////////////////
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

///////////////////////////////////////////////////////////teacher/////////////////////////////////////////////////
void Teacher_Menu()
{
    int teacher_menu_choice;

    char *teacher_menu = "1- Save your info\n"
                         "2- Look for some one\n"
                         "3- Return\n";

    struct Teacher Teacher;

    do
    {
        printf("%s", teacher_menu);
        scanf("%d", &teacher_menu_choice);
        system("cls");

        if (teacher_menu_choice == 1)
        {
            int teachercount = read_Teacher_Count();
            get_Teacher_info(&Teacher);
            teachercount++;
            adding_Teacher_info(&Teacher, teachercount);
            write_Teacher_Count(teachercount);
            system("pause");
            system("cls");
            
        }

        else if (teacher_menu_choice == 2)
        {
            Teacher_Search();
        }

        else if (teacher_menu_choice == 3)
        {
            break;
        }

        else
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n\n");
        }

    } while (1);

}

void get_Teacher_info(struct Teacher *Teacher)
{
    printf("Enter your First name: ");
    scanf("%32s", Teacher->Teacher_First_name);
    clearInputBuffer();

    printf("Enter your Last name: ");
    scanf("%32s", Teacher->Teacher_Last_name);
    clearInputBuffer();

    printf("Enter your Speciality: ");
    scanf("%32s", Teacher->Teacher_speciality);
    clearInputBuffer();
}

void adding_Teacher_info(const struct Teacher *Teacher, int TeacherCount)
{
    FILE *file = fopen("Teacher.txt", "a");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    fprintf(file, "----------------Teacher %d----------------\n", TeacherCount);
    fprintf(file, "First Name: %s\n", Teacher->Teacher_First_name);
    fprintf(file, "Last Name: %s\n", Teacher->Teacher_Last_name);
    fprintf(file, "Speciality: %s\n", Teacher->Teacher_speciality);
    fprintf(file, "-----------------------------------------\n");

    fclose(file);
    printf("Information saved to file successfully.\n");

}

int read_Teacher_Count()
{
    int count = 0;
    FILE *countFile = fopen("TeacherCount.txt", "r");

    if (countFile == NULL)
    {
        countFile = fopen("TeacherCount.txt", "w");
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

void write_Teacher_Count(int count)
{
    FILE *countFile = fopen("TeacherCount.txt", "w");

    if (countFile == NULL)
    {
        perror("Error writing count");
        return;
    }

    fprintf(countFile, "%d", count);
    fclose(countFile);

}

void Teacher_Search()
{
    int Teacher_search_choice;

    char *Teacher_Menu = "1- Search by name\n"
                   "2- Search by speciality\n"
                   "3- Return\n";

    do
    {

        printf("%s", Teacher_Menu);
        scanf("%d", &Teacher_search_choice);
        system("cls");

        if (Teacher_search_choice == 1)
        {

            char First_name[33], Last_name[33];
            printf("insert the first name of the Teacher your looking for: ");
            scanf("%32s", First_name);
            printf("Last name: ");
            scanf("%32s", Last_name);
            system("cls");

            check_Teacher_Info_by_name(First_name, Last_name);
            system("pause");
            system("cls");
        }

        else if (Teacher_search_choice == 2)
        {
            char speciality[33];
            printf("insert the age of Etudiant looking for: ");
            scanf("%s", speciality);
            system("cls");

            check_Teacher_Info_by_speciality(speciality);
            system("pause");
            system("cls");
        }

        else if (Teacher_search_choice == 3)
        {
            break;
        }

        else
        {
            printf("Invalid choice. Please enter 1, 2 or 3.\n\n");
        }

    } while (1);

}

void check_Teacher_Info_by_name(const char *firstName, const char *lastName)
{
    FILE *file = fopen("Teacher.txt", "r");

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

                        fgets(line, sizeof(line), file);
                        printf("%s", line);
                        printf("----------------------------------------------------------------\n");
                        
                    }
                }
            }
        }
    }

    fclose(file);

    if (!found)
    {
        system("cls");
        printf("Teacher not found.\n");
    }

}

void check_Teacher_Info_by_speciality(const char *speciality)
{
    FILE *file = fopen("Teacher.txt", "r");

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
        if (strstr(line, "Speciality: ") != NULL)
        {
            char Teacher_speciality[33];
            sscanf(line, "Speciality: %s", Teacher_speciality);

            if (strstr(Teacher_speciality, speciality) != NULL)
            {
                count++;
                found = 1;
            }
        }
    }

    fclose(file);

    if (found)
    {
        printf("----------------------Found %d Teachers(s) with the specified speciality-----------------------\n\n", count);

        file = fopen("Teacher.txt", "r");
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

            if (strstr(line, "Speciality: ") != NULL)
            {

                char Teacher_speciality[33];
                sscanf(line, "Speciality: %s", Teacher_speciality);

                if (strstr(Teacher_speciality, speciality) != NULL)
                {
                    for (int i = 0; i < 3; i++)
                        printf("%s", buffer[i]);

                    printf("---------------------------------------\n\n");
                }
            }
        }

        fclose(file);
    }
    else
    {
        system("cls");
        printf("No Teacher found with the specified speciality.\n");
    }
}

/////////////////////////////////////////////////////////Departement////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////Formation////////////////////////////////////////////////////////////////////////
void Formation_menu()
{
    int formation_menu_choice;

    char *menu = "1- Create formation\n"
                 "2- Look for formation\n"
                 "3- Return\n";

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
                printf("%s", line);
                while (fgets(line, sizeof(line), file) != NULL && !strstr(line, "////////////////"))
                {
                    printf("%s", line);
                }
                break;
            }
        }
    }

    fclose(file);
    if (!found)
    {
        printf("No Formation with that name is found\n");
    }
}
