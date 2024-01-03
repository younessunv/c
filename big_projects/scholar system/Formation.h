#ifndef FORMATION_H
#define FORMATION_H

#include "Modules.h"

typedef struct Formation
{
    char name[33];
    struct Modules modules[10];
    int moduleCount;
};


void Formation_menu();
void create_Formation(struct Formation *formation);
void save_Formation(const struct Formation *formation);
void search_formation(const char *formation_name);



#endif
