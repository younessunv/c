#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 30

void passwordGenerater(char *password, int length);

int main()
{
    int length, attempts = 0;

    printf("----------------insert -1 to leave.----------------");
    while(1)
    {
        do{
            printf("\ninsert how many characters you want in your password: ");
            scanf("%d", &length);
        }while(length <= 0 || length > MAX_LENGTH);

        if(length == -1)
            break;

        char password[length + 1];
        passwordGenerater(password, length);
        printf("%s\n", password);
        attempts++;

        
        if(attempts == 3)
        {
            system("cls");
            printf("----------------insert -1 to leave.----------------");
            attempts = 0;
        }
    }
    
    return 0;
}

void passwordGenerater(char *password, int length) 
{
    srand(time(NULL));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@$&*?";

    for(int i = 0; i < length; i++)
    {
        char randomIndex = rand() % (sizeof(charset) - 1);
        password[i] = charset[randomIndex];
    }

    password[length] = '\0';

}
