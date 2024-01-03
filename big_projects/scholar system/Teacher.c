#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Teacher.h"

struct Teacher Teacher;


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
            
        }

        else if (teacher_menu_choice == 2)
        {
            
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