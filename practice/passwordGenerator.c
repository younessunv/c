#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LENGTH 30
#define EXIT_CODE -1

void passwordGenerater(char *password, int length);

int main()
{
    srand(time(NULL));
    int length, attempts = 0;
    bool continueInput = true;

    printf("----------------insert -1 to leave.----------------");
    do
    {
        printf("\nInsert how many characters you want in your password: ");
        
        if (scanf("%d", &length) != 1)      
        {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid integer.");
            continue;
        }

        if (length == EXIT_CODE)
        {
            continueInput = false;
        }
        else if (length <= 0 || length > MAX_LENGTH)
        {
            printf("Invalid input. Length should be between 1 and %d.\n", MAX_LENGTH);
        }
        else
        {
            char password[length + 1];
            passwordGenerater(password, length);
            printf("%s\n", password);
            attempts++;

            if (attempts == 3)
            {
                system("pause");
                system("cls");
                printf("----------------Insert -1 to leave.----------------");
                attempts = 0;
            }
        }
    } while (continueInput);

    return 0;
}

void passwordGenerater(char *password, int length)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@$&*?";

    for (int i = 0; i < length; i++)
    {
        char randomIndex = rand() % (sizeof(charset) - 1);
        password[i] = charset[randomIndex];
    }

    password[length] = '\0';
}
