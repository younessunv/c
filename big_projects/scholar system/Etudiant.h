#ifndef ETUDIANT_H
#define ETUDIANT_H

typedef struct Etudiant
{
    char Etudiant_First_name[33];
    char Etudiant_last_name[33];
    int Etudiant_age;
    char Etudiant_city[33];
    char Etudiant_formation[33];
};

void get_Etudiant_Info(struct Etudiant *Etudiant);
void adding_Etudiant_info(const struct Etudiant *Etudiant, int personCount);
int read_Etudiant_Count();
void write_etudiant_Count(int count);
void check_Etudiant_Info_by_name(const char *firstName, const char *lastName);
void check_Etudiant_Info_by_age(const int age);
void check_Etudiant_Info_by_city(const char *city);
void check_Etudiant_Info_by_formation(const char *formation);

#endif
