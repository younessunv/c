#include <stdio.h>

int main()
{
    char string1[33], string2[33];

    fputs("would insert the first string: ", stdout);
    fgets(string1, 33, stdin);
    fputs("would insert the second string: ", stdout);
    fgets(string2, 33, stdin);

    compare(string1, string2);
    return 0;
}

void compare(char *string1,char *string2)
{
    int equals = 1;

    while(*string1 != '\0' && *string2 != '\0')
    {
        if(*string1 != *string2)
        {
            equals = 0;
            break;
        }
        string1++;
        string2++;
    }

    if(equals)
        printf("The two strings are equle.");
    else
        printf("The two strings are not equqle (different).");
}