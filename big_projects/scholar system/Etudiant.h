#ifndef ETUDIANT_H
#define ETUDIANT_H

struct Etudiant
{
    char user_name[33];
    int age;
    char formation[33];
};

void get_Etudiant_Info(struct Etudiant *person);
void adding_Etudiant_info(const struct Etudiant *person, int personCount);
int read_Etudiant_Count();
void write_etudiant_Count(int count);
void search_Etudiant_Info(char *textToFind);

#endif