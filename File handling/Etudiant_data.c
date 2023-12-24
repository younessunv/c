#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct Etudiant
{
    char user_name[33];
    int age;
    char formation[33];
};


void getPersonInfo(struct Etudiant *person);
void adding_data(const struct Etudiant *person, int personCount);
int readPersonCount();
void writePersonCount(int count);


int main()
{
    int personCount = readPersonCount();
    struct Etudiant person;

    getPersonInfo(&person);
    personCount++;

    adding_data(&person, personCount);
    writePersonCount(personCount);

    return 0;
}

void getPersonInfo(struct Etudiant *person)
{
    printf("Enter your user name: ");
    scanf("%32s", person->user_name);

    printf("Enter your age: ");
    scanf("%d", &person->age);

    printf("Enter your formation: ");
    scanf("%32s", person->formation);
}

void adding_data(const struct Etudiant *person, int personCount)
{
    FILE *file = fopen("Etudiant.txt", "a");

     if (file == NULL) {
        perror("Error");
        return;
    }

    fprintf(file, "----------------person %d----------------\n", personCount);
    fprintf(file, "User Name: %s\n", person->user_name);
    fprintf(file, "Age: %d\n", person->age);
    fprintf(file, "Formation: %s\n", person->formation);
    fprintf(file, "-----------------------------------------\n");


    fclose(file);
    printf("Information saved to file successfully.\n");
}

int readPersonCount()
{
    int count;
    FILE *countFile = fopen("PersonCount.txt", "r");

    if (countFile == NULL)
    {
        return 0;
    }

    fscanf(countFile, "%d", &count);
    fclose(countFile);

    return count;
}

void writePersonCount(int count)
{
    FILE *countFile = fopen("PersonCount.txt", "w");

    if (countFile == NULL)
    {
        perror("Error writing count");
        return;
    }

    fprintf(countFile, "%d", count);
    fclose(countFile);
}