#include <stdio.h>
#include <string.h>

int main()
{
    char string[25];
    int len;

    printf("insert your message: ");
    fgets(string, 25, stdin);

    len = strlen(string);
    string[len - 1] = '\0';

    for(int i = len - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }
}