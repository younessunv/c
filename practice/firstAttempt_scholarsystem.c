#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct Departement
{
    char name[33];

} Departement;

typedef struct Teacher
{
    char first_name[33];
    char last_name[33];
    char speciality[33];
    Departement departement;

}Teacher;

typedef struct Module
{
    char name[33];
    char Time_Table[50];
    Teacher teacher;

}Module;

typedef struct Formation
{
    char name[33];
    Module module[10];
    
}Formation;

typedef struct Etudiant
{
    char first_name[33];
    char last_name[33];
    int age;
    char city[33];
    Formation formation;

}Etudiant;

////////////////////////////////////////////////////////////////////Depatment////////////////////////////////////////////////////////////////
void Departement_menu();
void create_Departement(Departement *departement);
void save_Departement(const Departement *departement, int count);
void search_Departement();
int read_Departement_Count();
void write_Departement_Count(int count);
/////////////////////////////////////////////////////////////////////Teacher//////////////////////////////////////////////////////////
void Teacher_Menu();
void get_Teacher_info(Teacher *teacher);
void choose_departement(Teacher *teacher);
void adding_Teacher_info(const Teacher *teacher, int Count);
void list_all_Teachers();
void Teacher_Search();
void check_Teacher_Info_by_name(const char *firstName, const char *lastName);
void check_Teacher_Info_by_speciality(const char *speciality);
void check_Teacher_Info_by_departement(const char *departement);
int read_Teacher_Count();
void write_Teacher_Count(int count);
////////////////////////////////////////////////////////////////////Modules////////////////////////////////////////////////////////////
void Module_Menu();
void get_Module_info(Module *module);
void choose_Teacher(Module *module);
void adding_Module_info(const  Module *module, int modulecount);
void list_all_modules();
int read_Module_Count();
void write_Module_Count(int count);
/////////////////////////////////////////////////////////////////Formation/////////////////////////////////////////////////////
void Formation_Menu();
void get_Formation_name(Formation *formation);
int choose_Module(Formation *formation);
void adding_Formation_info(const Formation *formation, int formationcount, int x);
void list_all_Formation();
void search_Formation_by_name(const char *name);
int read_Formation_Count();
void write_Formation_Count(int count);
///////////////////////////////////////////////////////////////Etudiant/////////////////////////////////////////////////////////
void Etudiant_menu();
void get_Etudiant_Info(Etudiant *etudiant);
void choose_formation(Etudiant *etudiant);
void adding_Etudiant_info(const Etudiant *etudiant, int etudiantCount);
void Etudiant_Search();
void check_Etudiant_Info_by_name(const char *firstName, const char *lastname);
void check_Etudiant_Info_by_age(const int age);
void check_Etudiant_Info_by_city(const char *city);
void check_Etudiant_Info_by_formation(const char *formation);
void list_all_Etudiants();
int read_Etudiant_Count();
void write_etudiant_Count(int count);




int main()
{

    Departement departement;
    Teacher teacher;
    Module module;
    Formation formation;
    Etudiant etudiant;


    do{
        int departementCount = read_Departement_Count();
        int teacherCount = read_Teacher_Count();
        int moduleCount = read_Module_Count();
        int formationCount = read_Formation_Count();
        int etudiantCount = read_Etudiant_Count();

        char menu[150];
        int menu_choice;

        sprintf(menu , "1- Etduiant  {%d}\n"
                 "2- Formation  {%d}\n"
                 "3- Modules  {%d}\n"
                 "4- Teacher  {%d}\n"
                 "5- Departement {%d}\n"
                 "6- Exit\n", etudiantCount, formationCount, moduleCount, teacherCount, departementCount);


        printf("%s", menu);
        scanf("%d", &menu_choice);
        system("cls");

        if (menu_choice == 1)
        {
            if ( departementCount <= 0 || teacherCount <= 0 || moduleCount < 3 || formationCount <= 0)
            {
                printf("Following the scholar system , You can't create a Formation without having at least single department and a single Teacher and at least three modules and a formation.\nMake sure they all exist\n\n");
                system("pause");
                system("cls");
            }

            else
            {
                Etudiant_menu();
            }
        }

        else if (menu_choice == 2)
        {
            if ( departementCount <= 0 || teacherCount <= 0 || moduleCount < 3)
            {
                printf("Following the scholar system , You can't create a Formation without having at least a single department and a single Teacher and at least three modules.\nMake sure they all exist\n\n");
                system("pause");
                system("cls");
            }

            else
            {
                Formation_Menu();
            }
        }
        
        else if (menu_choice == 3)
        {
             if ( departementCount <= 0 || teacherCount <= 0)
            {   
                printf("Following the scholar system , You can't create a Module without having at least single department and a single Teacher.\nMake sure they both exixst\n\n");
                system("pause");
                system("cls");
            }

            else
            {
                Module_Menu();
            }
        }

        else if (menu_choice == 4)
        {
            if ( departementCount <= 0)
            {
                printf("Following the scholar system , You can't create a teacher without having at least single department.\nTry to create a departement first\n\n");
                system("pause");
                system("cls");
            }

            else
            {
                Teacher_Menu();
            }
        }

        else if (menu_choice == 5)
        {
            Departement_menu();
        }

        else if (menu_choice == 6)
        {
            break;
        }

        else
        {
            printf("Invalid choice. Please enter 1, 2, 3, 4, 5 or 6.\n\n");
        }

    }while(1);

    return 0;
}


///////////////////////////////////////////////////////////////Department;///////////////////////////////////////////////////////////////
void Departement_menu()
{
    Departement departement;

    int menu_choice;

    char *menu = "1- Create Departement\n"
                 "2- List THe Departments\n"
                 "3- Return\n";

    do
    {
        printf("%s", menu);
        scanf("%d", &menu_choice);
        system("cls");

        if (menu_choice == 1)
        {
            int departementCount = read_Departement_Count();

            create_Departement(&departement);
            save_Departement(&departement, departementCount);

            departementCount++;
            write_Departement_Count(departementCount);
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
    printf("What is the name of your Departement: ");
    fflush(stdin);
    fgets(departement->name, sizeof(departement->name), stdin);

    size_t len = strlen(departement->name);
    if (len > 0 && departement->name[len - 1] == '\n') {
        departement->name[len - 1] = '\0';
    }
}

void save_Departement(const Departement *departement, int count)
{
    FILE *file = fopen("departement.txt", "a");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    fprintf(file, "Departement N* %d: %s\n", count + 1, departement->name);

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

int read_Departement_Count()
{
    int count = 0;
    FILE *countFile = fopen("department.txt", "r");

    if (countFile == NULL)
    {
        countFile = fopen("department.txt", "w");
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
        if (fscanf(countFile, "%d", &count) != 1)
        {
            count = 0;
        }
        fclose(countFile);
    }

    return count;
}

void write_Departement_Count(int count)
{
    FILE *countFile = fopen("department.txt", "w");

    if (countFile == NULL)
    {
        perror("Error writing count");
        return;
    }

    fprintf(countFile, "%d", count);
    fclose(countFile);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////Teacher/////////////////////////////////////////////////////////////////////////////

void Teacher_Menu()
{
    int teacher_menu_choice;

    char *teacher_menu = "1- Save your info\n"
                         "2- list all Teachers\n"
                         "3- Look for some one\n"
                         "4- Return\n";

    Teacher teacher;

    do
    {
        printf("%s", teacher_menu);
        scanf("%d", &teacher_menu_choice);
        system("cls");

        if (teacher_menu_choice == 1)
        {
            int teachercount = read_Teacher_Count();

            get_Teacher_info(&teacher);
            choose_departement(&teacher);

            teachercount++;


            adding_Teacher_info(&teacher, teachercount);
            write_Teacher_Count(teachercount);
            system("pause");
            system("cls");
            
        }

        else if (teacher_menu_choice == 2)
        {
            list_all_Teachers();
            system("pause");
            system("cls");
        }

        else if (teacher_menu_choice == 3)
        {
            Teacher_Search();
        }

        else if (teacher_menu_choice == 4)
        {
            break;
        }

        else
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n\n");
        }

    } while (1);

}

void get_Teacher_info(Teacher *teacher)
{
    printf("Enter the First name: ");
    scanf("%32s", teacher->first_name);

    printf("Enter the Last name: ");
    scanf("%32s", teacher->last_name);

    printf("Enter the Speciality: ");
    fflush(stdin);
    fgets(teacher->speciality, sizeof(teacher->speciality), stdin);

    size_t len = strlen(teacher->speciality);
    if (len > 0 && teacher->speciality[len - 1] == '\n') {
        teacher->speciality[len - 1] = '\0';
    }
}

void choose_departement(Teacher *teacher)
{
    FILE *file = fopen("departement.txt", "r");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    printf("-----------------------/// Select the department to which the Teacher will be assigned: \\\\\\-----------------------\n");

    char line[50], count, i = 0;
    char department[50][33];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "Departement N* %d: %[^\n]", &count, department[i]) == 2)
        {
            printf("%d- %s\t\t", i + 1, department[i]);
            i++;

            if (i % 4 == 0)
                printf("\n");
        }
    }

    if (i % 4 != 0)
        printf("\n");

    fclose(file);

    int choice;
    printf("\nEnter the number of the department: \n");
    
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > i)
    {
        while (getchar() != '\n');

        printf("Invalid choice. Please enter a number between 1 and %d: \n", i);
    }

    char selectedDepartment[33];
    strcpy(selectedDepartment, department[choice - 1]);

    printf("You selected: %s\n\n", selectedDepartment);
    strcpy(teacher->departement.name, selectedDepartment);
}

void adding_Teacher_info(const  Teacher *teacher, int TeacherCount)
{
    FILE *file = fopen("teacher.txt", "a");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    fprintf(file, "----------------Teacher %d----------------\n", TeacherCount);
    fprintf(file, "First Name: %s\n", teacher->first_name);
    fprintf(file, "Last Name: %s\n", teacher->last_name);
    fprintf(file, "Speciality: %s\n", teacher->speciality);
    fprintf(file, "Department: %s\n", teacher->departement.name);
    fprintf(file, "-----------------------------------------\n");

    fclose(file);
    printf("Information saved to file successfully.\n");

}

void list_all_Teachers()
{
    FILE *file = fopen("teacher.txt", "r");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    char line[75];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        found = 1;
        printf("%s", line);
    }

    fclose(file);
    if(!found)
    {
        printf("no content found on the file try insert some Teachers\n");
    }
}

void Teacher_Search()
{
    int Teacher_search_choice;

    char *Teacher_Menu = "1- Search by name\n"
                   "2- Search by speciality\n"
                   "3- Seach by departement\n"
                   "4- Return\n";

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
            printf("insert the speciality of the Teacher looking for: ");
            scanf("%s", speciality);
            system("cls");

            check_Teacher_Info_by_speciality(speciality);
            system("pause");
            system("cls");
        }

        else if (Teacher_search_choice == 3)
        {
            char departement[33];
            printf("insert the departement of the Teacher looking for: ");
            scanf("%s", departement);
            system("cls");

            check_Teacher_Info_by_departement(departement);
            system("pause");
            system("cls");
        }

        else if (Teacher_search_choice == 4)
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
    FILE *file = fopen("teacher.txt", "r");

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
                        found = 1;

                        printf("----------------------------------------------------------------\n");
                        printf("%s", previous_line);
                        printf("%s", line);
                        
                        for(int i = 0; i < 2; i++)
                        {
                            fgets(line, sizeof(line), file);
                            printf("%s", line);
                        }
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
    FILE *file = fopen("teacher.txt", "r");

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
                    {
                        printf("%s", buffer[i]);
                    }

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
        printf("No Teacher found with the specified speciality.\n");
    }
}

void check_Teacher_Info_by_departement(const char *departement)
{
    FILE *file = fopen("teacher.txt", "r");

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
        if (strstr(line, "Department: ") != NULL)
        {
            char Teacher_departement[33];
            sscanf(line, "Department: %s", Teacher_departement);

            if (strstr(Teacher_departement, departement) != NULL)
            {
                count++;
                found = 1;
            }
        }
    }

    fclose(file);

    if (found)
    {
        printf("----------------------Found %d Teachers(s) with the specified departement-----------------------\n\n", count);

        file = fopen("Teacher.txt", "r");
        if (file == NULL)
        {
            perror("Error opening file");
            return;
        }

        while (fgets(line, sizeof(line), file))
        {
            strcpy(buffer[0], buffer[1]);
            strcpy(buffer[1], buffer[2]);
            strcpy(buffer[2], buffer[3]);
            strcpy(buffer[3], line);

            if (strstr(line, "Department: ") != NULL)
            {

                char Teacher_departement[33];
                sscanf(line, "Department: %s", Teacher_departement);

                if (strstr(Teacher_departement, departement) != NULL)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        printf("%s", buffer[i]);
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
        printf("No Teacher found with the specified departement.\n");
    }
}

int read_Teacher_Count()
{
    int count = 0;
    FILE *countFile = fopen("teacherCount.txt", "r");

    if (countFile == NULL)
    {
        countFile = fopen("teacherCount.txt", "w");
        if (countFile != NULL)
        {
            fprintf(countFile, "0");
            fclose(countFile);
        }
        else
        {
            perror("Error creating and initializing TeacherCount.txt");
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
    FILE *countFile = fopen("teacherCount.txt", "w");

    if (countFile == NULL)
    {
        perror("Error writing count");
        return;
    }

    fprintf(countFile, "%d", count);
    fclose(countFile);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////Module///////////////////////////////////////////////////////////////////////////

void Module_Menu()
{
    int menu_choice;

    char *menu = "1- Make Module(s)\n"
                 "2- List all the Modules\n"
                 "3- Look for a Module\n"
                 "4- Return\n";

    Module module;

    do
    {
        printf("%s", menu);
        scanf("%d", &menu_choice);
        system("cls");

        if (menu_choice == 1)
        {
            int moduleCount = read_Module_Count();
            
            get_Module_info(&module);
            choose_Teacher(&module);

            moduleCount++;

            adding_Module_info(&module, moduleCount);
            write_Module_Count(moduleCount);
            system("pause");
            system("cls");
            
        }

        else if (menu_choice == 2)
        {
            list_all_modules();
            system("pause");
            system("cls");
        }

        else if (menu_choice == 3)
        {
            break;
        }

        else if (menu_choice == 4)
        {
            break;
        }

        else
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n\n");
        }

    } while (1);

}

void get_Module_info(Module *module)
{
    printf("Enter the name of the module: ");
    scanf("%32s", module->name);

    printf("Enter the table time: ");
    scanf("%32s", module->Time_Table);
}

void choose_Teacher(Module *module) {
    FILE *file = fopen("teacher.txt", "r");

    if (file == NULL) {
        perror("Error");
        return;
    }

    printf("-----------------------/// Choose the Teacher who will be assigned the Module: \\\\\\-----------------------\n");

    char line[50], first_names[50][33], last_names[50][33];
    int count = 0, i = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, "First Name: %s", first_names[i]) == 1) {
            fgets(line, sizeof(line), file);
            if (sscanf(line, "Last Name: %s", last_names[i]) == 1) {
                printf("%d- %s %s\t\t", count + 1, first_names[i], last_names[i]);
                i++;
                count++;

                if (i % 4 == 0)
                    printf("\n");
            }
        }
    }

    if (i % 4 != 0)
        printf("\n");

    fclose(file);

    int choice;
    printf("\nEnter the number of the Teacher: \n");

    while (scanf("%d", &choice) != 1 || choice < 1 || choice > i) {
        while (getchar() != '\n');
        printf("Invalid choice. Please enter a number between 1 and %d: \n", i);
    }

    if (choice >= 1 && choice <= i) {
        char selectedTeacher[67];
        snprintf(selectedTeacher, sizeof(selectedTeacher), "%s %s", first_names[choice - 1], last_names[choice - 1]);
        printf("You selected: %s\n\n", selectedTeacher);
        strcpy(module->teacher.first_name, selectedTeacher);
    }
}

void adding_Module_info(const  Module *module, int modulecount)
{
    FILE *file = fopen("module.txt", "a");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    fprintf(file, "----------------Module %d----------------\n", modulecount);
    fprintf(file, "Name: %s\n", module->name);
    fprintf(file, "Time table: %s\n", module->Time_Table);
    fprintf(file, "Teacher: %s\n", module->teacher.first_name);
    fprintf(file, "-----------------------------------------\n");

    fclose(file);
    printf("Information saved to file successfully.\n");
}

void list_all_modules()
{
    FILE *file = fopen("module.txt", "r");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    char line[75];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        found = 1;
        printf("%s", line);
    }

    fclose(file);
    if(!found)
    {
        printf("no content found on the file try insert some modules\n");
    }
}

int read_Module_Count()
{
    int count = 0;
    FILE *countFile = fopen("moduleCount.txt", "r");

    if (countFile == NULL)
    {
        countFile = fopen("moduleCount.txt", "w");
        if (countFile != NULL)
        {
            fprintf(countFile, "0");
            fclose(countFile);
        }
        else
        {
            perror("Error creating and initializing ModuleCount.txt");
            return 0;
        }
    }
    else
    {
        if (fscanf(countFile, "%d", &count) != 1)
        {
            count = 0;
        }
        fclose(countFile);
    }

    return count;
}

void write_Module_Count(int count)
{
    FILE *countFile = fopen("moduleCount.txt", "w");

    if (countFile == NULL)
    {
        perror("Error writing count");
        return;
    }

    fprintf(countFile, "%d", count);
    fclose(countFile);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////Formation///////////////////////////////////////////////////////////////////////
void Formation_Menu()
{
    int menu_choice;

    char *menu = "1- Make Formation\n"
                 "2- List all the Formation\n"
                 "3- Look for a Formation\n"
                 "4- Return\n";

    Formation formation;

    do
    {

        printf("%s", menu);
        scanf("%d", &menu_choice);
        system("cls");

        if (menu_choice == 1)
        {
            int formationcount = read_Formation_Count();

            get_Formation_name(&formation);
            int x = choose_Module(&formation);
            formationcount++;

            adding_Formation_info(&formation, formationcount, x);
            write_Formation_Count(formationcount);
            system("pause");
            system("cls");
        }

        else if (menu_choice == 2)
        {
            list_all_Formation();
            system("pause");
            system("cls");
        }

        else if (menu_choice == 3)
        {
            char formation_name[50];
            printf("type the name of the Formation you looking for: ");
            scanf("%s", formation_name);
            system("cls");

            search_Formation_by_name(formation_name);
            system("pause");
            system("cls");
        }

        else if (menu_choice == 4)
        {
            break;
        }

        else
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n\n");
        }

    } while (1);

}

void get_Formation_name(Formation *formation)
{
    printf("Enter the name of the formation: ");
    scanf("%32s", formation->name);
}

int choose_Module(Formation *formation)
{
    FILE *file = fopen("module.txt", "r");

    if (file == NULL) {
        perror("Error");
        return -1;
    }

    printf("\n\n-----------------------/// Choose the modesl that will form the formation.: \\\\\\-----------------------\n");

    int x;
    do
    {
        printf("\nFrom {3 to 10} choose how many modules to create the Formation: ");
        scanf("%d", &x);
        system("cls");

    } while (x < 3 || x > 10);

    char line[50], buffer[50][33];
    int i = 0;
    
    while(fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "Name: %s", buffer[i]) == 1)
        {
            printf("%d- %s\t\t", i + 1, buffer[i]);
            i++;

            if (i % 4 == 0)
            {
                printf("\n");
            }
        }
    }

    if (i % 4 != 0)
        printf("\n");

    fclose(file);

    for (int j = 0; j < x; j++)
    {
        int choice;
        printf("\nEnter the number of the Module %d: ", j + 1);

        while (scanf("%d", &choice) != 1 || choice < 1 || choice > i)
        {
            while (getchar() != '\n');
            printf("Invalid choice. Please enter a number between 1 and %d: \n", i);
        }

        if (choice >= 1 && choice <= i)
        {
            snprintf(formation->module[j].name, sizeof(formation->module[j].name), "%s", buffer[choice - 1]);
            printf("You selected: %s\n", formation->module[j].name);
        }
    }

    return x;
}

void adding_Formation_info(const Formation *formation, int formationcount, int x)
{
    FILE *file = fopen("formation.txt", "a");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    fprintf(file, "----------------formation %d----------------\n", formationcount);
    fprintf(file, "Name: %s\n", formation->name);

    for (int j = 0; j < x; j++)
    {
        if (formation->module[j].name[0] != '\0')
        {
            fprintf(file, "Module %d: %s\n", j + 1, formation->module[j].name);
        }
    }
    fprintf(file, "-----------------------------------------\n");

    fclose(file);
    printf("\nInformation saved to file successfully.\n");
}

void list_all_Formation()
{
    FILE *file = fopen("formation.txt", "r");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    char line[75];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        found = 1;
        printf("%s", line);
    }
    printf("\n");

    fclose(file);
    if(!found)
    {
        printf("no content found try insert some formation\n");
    }
}

void search_Formation_by_name(const char *name)
{
    FILE *file = fopen("formation.txt", "r");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    char line[75], buffer[50];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if(strstr(line, "Name: ") != NULL)
        {
            sscanf(line, "Name: %s", buffer);
            if(strcmp(buffer, name) == 0)
            {
                found = 1;

                while(1)
                {
                    printf("%s", line);
                    fgets(line, sizeof(line), file);

                    if ( strstr(line, "-----------------------------------------") != NULL)
                    {
                        break;
                    }
                }

            }
        }
    }
    printf("\n");

    fclose(file);
    if(!found)
    {
        printf("no formation found with the name your looking for.\n");
    }
}

int read_Formation_Count()
{
    int count = 0;
    FILE *countFile = fopen("formationCount.txt", "r");

    if (countFile == NULL)
    {
        countFile = fopen("formationCount.txt", "w");
        if (countFile != NULL)
        {
            fprintf(countFile, "0");
            fclose(countFile);
        }
        else
        {
            perror("Error creating and initializing FormationCount.txt");
            return 0;
        }
    }
    else
    {
        if (fscanf(countFile, "%d", &count) != 1)
        {
            count = 0;
        }
        fclose(countFile);
    }

    return count;
}

void write_Formation_Count(int count)
{
    FILE *countFile = fopen("formationCount.txt", "w");

    if (countFile == NULL)
    {
        perror("Error writing count");
        return;
    }

    fprintf(countFile, "%d", count);
    fclose(countFile);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////Etudiant///////////////////////////////////////////////////////////////////////
void Etudiant_menu()
{
    int menu_choice;

    char *menu = "1- Save Etudiant info\n"
                 "2- Look for and Etudiant\n"
                 "3- List all Etudiants\n"
                 "4- Return\n";

    Etudiant etudiant;

    do
    {
        printf("%s", menu);
        scanf("%d", &menu_choice);
        system("cls");

        if (menu_choice == 1)
        {
            int etudiantCount = read_Etudiant_Count();
            get_Etudiant_Info(&etudiant);
            choose_formation(&etudiant);
            etudiantCount++;

            adding_Etudiant_info(&etudiant, etudiantCount);
            write_etudiant_Count(etudiantCount);
            system("pause");
            system("cls");
        }

        else if (menu_choice == 2)
        {
            Etudiant_Search();
        }

        else if (menu_choice == 3)
        {
            list_all_Etudiants();
            system("pause");
            system("cls");
        }

        else if (menu_choice == 4)
        {
            break;
        }

        else
        {
            printf("Invalid choice. Please enter 1, 2, 3 or 4.\n\n");
        }

    } while (1);

}

void get_Etudiant_Info(Etudiant *etudiant)
{
    printf("Enter your First name: ");
    scanf("%32s", etudiant->first_name);

    printf("Enter your Last name: ");
    scanf("%32s", etudiant->last_name);

    printf("Enter your age: ");
    scanf("%d", &etudiant->age);

    printf("Enter your city: ");
    scanf("%32s", etudiant->city);

}

void choose_formation(Etudiant *etudiant)
{
    FILE *file = fopen("formation.txt", "r");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    printf("\n-----------------------/// Decide which formation the student will be allocated to.: \\\\\\-----------------------\n");

    char line[50], count, i = 0;
    char formation[50][33];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "Name : %s", formation[i]) == 1)
        {
            printf("%d- %s\t\t", i + 1, formation[i]);
            i++;

            if (i % 4 == 0)
                printf("\n");
        }
    }

    if (i % 4 != 0)
        printf("\n");

    fclose(file);

    int choice;
    printf("\nEnter the number of the Formation: \n");
    
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > i)
    {
        while (getchar() != '\n');

        printf("Invalid choice. Please enter a number between 1 and %d: \n", i);
    }

    char selectedFormation[33];
    strcpy(selectedFormation, formation[choice - 1]);

    printf("You selected: %s\n\n", selectedFormation);
    strcpy(etudiant->formation.name, selectedFormation);

}

void adding_Etudiant_info(const Etudiant *etudiant, int etudiantCount)
{
    FILE *file = fopen("etudiant.txt", "a");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    fprintf(file, "----------------Etudiant %d----------------\n", etudiantCount);
    fprintf(file, "First Name: %s\n", etudiant->first_name);
    fprintf(file, "Last Name: %s\n", etudiant->last_name);
    fprintf(file, "Age: %d\n", etudiant->age);
    fprintf(file, "City: %s\n", etudiant->city);
    fprintf(file, "Formation: %s\n", etudiant->formation.name);
    fprintf(file, "-----------------------------------------\n");

    fclose(file);
    printf("Information saved to file successfully.\n");
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
    FILE *file = fopen("etudiant.txt", "r");

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
    FILE *file = fopen("etudiant.txt", "r");

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
    FILE *file = fopen("etudiant.txt", "r");

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
    FILE *file = fopen("etudiant.txt", "r");

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
        printf("No Etudiant found with the specified formation.\n");
    }
}

void list_all_Etudiants()
{
    FILE *file = fopen("etudiant.txt", "r");

    if (file == NULL)
    {
        perror("Error");
        return;
    }

    char line[75];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        found = 1;
        printf("%s", line);
    }
    printf("\n");

    fclose(file);
    if(!found)
    {
        printf("no content found try insert some Etudiant info\n");
    }
}

int read_Etudiant_Count()
{
    int count = 0;
    FILE *countFile = fopen("etudiantCount.txt", "r");

    if (countFile == NULL)
    {
        countFile = fopen("etudiantCount.txt", "w");
        if (countFile != NULL)
        {
            fprintf(countFile, "0");
            fclose(countFile);
        }
        else
        {
            perror("Error creating and initializing etudiantCount.txt");
            return 0;
        }
    }
    else
    {
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
    FILE *countFile = fopen("etudiantCount.txt", "w");

    if (countFile == NULL)
    {
        perror("Error writing count");
        return;
    }

    fprintf(countFile, "%d", count);
    fclose(countFile);
}