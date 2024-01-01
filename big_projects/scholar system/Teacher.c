#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Teacher.h"

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
                   "5- Return\n";

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
            sscanf(line, "Speciality: %s", speciality);

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
                sscanf(line, "Speciality: %s", speciality);

                if (strstr(Teacher_speciality, speciality) != NULL)
                {
                    // Print the 2 lines before Age, Age line, and 1 line after Age
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

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
