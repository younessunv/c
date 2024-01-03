#ifndef TEACHER_H
#define TEACHER_H

struct Teacher
{
    char Teacher_First_name[33];
    char Teacher_Last_name[33];
    char Teacher_speciality[33];
};

void Teacher_Menu();
void get_Teacher_info(struct Teacher *Teacher);
void adding_Teacher_info(const struct Teacher *Teacher, int TeacherCount);
int read_Teacher_Count();
void write_Teacher_Count(int count);
void Teacher_Search();
void check_Teacher_Info_by_name(const char *firstName, const char *lastName);
void check_Teacher_Info_by_speciality(const char *speciality);

#endif
