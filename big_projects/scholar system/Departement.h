#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

typedef struct Departement
{
    char name[33];
    int departementCount;
};

int totalDepartments = 0;


void Departement_menu();
void create_Departement(struct Departement *departement);
void save_Departement(const struct Departement *departement);
void search_Departement();



#endif
