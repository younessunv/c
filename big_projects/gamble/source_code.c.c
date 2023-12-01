#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_RANDOM_NUMBER 20

int ordered_checker(int input[], int random[], int option);
int disordered_checker(int input[], int random[], int option);
int game();

int main()
{
    char play[4];

    do
    {
        printf("Do you want to play? (yes/no): ");
        scanf("%3s", play);

        // Convert the input to lowercase
        for (int i = 0; play[i]; i++)
        {
            play[i] = tolower(play[i]);
        }

        if (strcmp(play, "yes") == 0)
        {
            printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\================Let's play!================//////////////");
            game();
        }
        else if (strcmp(play, "no") == 0)
        {
            printf("Thanks for your time. Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid input. Please enter 'yes' or 'no'.\n");
        }
    }while(strcmp(play, "yes") == 0);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int game()
{
    int i, guesses, input[7], option, attempts, correctGuesses = 0;
    char order[20];

    // creating our menu.
    char *menu = "\n1-option: 3\n"
                 "2-option: 5\n"
                 "3-option: 7\n"
                 "Select the number of colones you wish to risk please: ";

    // choosing an option of two {ordered/ disordered}
    do
    {
        printf("\nchoose which mode you wanna play, insert {ordered / disordered}:\n");
        scanf("%s", order);
    } while (strcmp(order, "ordered") != 0 && strcmp(order, "disordered") != 0);

    // showing the menu and taking the input
    do
    {
        printf("%s", menu);
        scanf("%d", &option);
    } while (option != 3 && option != 5 && option != 7);

    // randomize the number asked to
    srand(time(NULL));
    int random[7];

    for (i = 0; i < option; i++)
    {
        int newRandom;
        int duplicate;
        do
        {
            duplicate = 0;
            newRandom = rand() % MAX_RANDOM_NUMBER + 1;

            // Check for duplicates within the generated numbers
            for (int j = 0; j < i; j++)
            {
                if (newRandom == random[j])
                {
                    duplicate = 1;
                    break;
                }
            }
        } while (duplicate);

        random[i] = newRandom;
    }

    /*---------------------------------------------------------------DISORDERED:-----------------------------------------------------------------*/

    // working with the case of option 3
    if (strcmp(order, "disordered") == 0)
    {
        if (option == 3)
        {
            printf("\n* * *\n");
            while (correctGuesses != 1)
            {
                // Get user guesses
                for (i = 0; i < option; i++)
                {
                    scanf("%d", &input[i]);
                }

                // Check if guesses are correct
                disordered_checker(input, random, option);

                if (guesses == option)
                {
                    correctGuesses = 1;
                    break;
                }
            }
        }

        // working with the case of option 5
        if (option == 5)
        {
            printf("\n* * * * *\n");
            while (correctGuesses != 1)
            {
                // Get user guesses
                for (i = 0; i < option; i++)
                {
                    scanf("%d", &input[i]);
                }

                // Check if guesses are correct
                disordered_checker(input, random, option);

                if (guesses == option)
                {
                    correctGuesses = 1;
                    break;
                }
            }
        }

        // working with the case of option 7
        if (option == 7)
        {
            printf("\n* * * * * * *\n");
            while (correctGuesses != 1)
            {
                // Get user guesses
                for (i = 0; i < option; i++)
                {
                    scanf("%d", &input[i]);
                }

                // Check if guesses are correct
                disordered_checker(input, random, option);

                if (guesses == option)
                {
                    correctGuesses = 1;
                    break;
                }
            }
        }
    }

    /*---------------------------------------------------------------ORDERED:-----------------------------------------------------------------*/
    if (strcmp(order, "ordered") == 0)
    {
        // working with the case of option 3
        if (option == 3)
        {
            printf("\n* * *\n");
            while (correctGuesses != 1)
            {
                // Get user guesses
                for (i = 0; i < option; i++)
                {
                    scanf("%d", &input[i]);
                }

                // Check if guesses are correct
                ordered_checker(input, random, option);

                if (guesses == option)
                {
                    correctGuesses = 1;
                    break;
                }
            }
        }

        // working with the case of option 5
        if (option == 5)
        {
            printf("\n* * * * *\n");
            while (correctGuesses != 1)
            {
                // Get user guesses
                for (i = 0; i < option; i++)
                {
                    scanf("%d", &input[i]);
                }

                // Check if guesses are correct
                ordered_checker(input, random, option);

                if (guesses = option)
                {
                    correctGuesses = 1;
                    break;
                }
            }
        }

        // working with the case of option 7
        if (option == 7)
        {
            printf("\n* * * * * * *\n");
            while (correctGuesses != 1)
            {
                // Get user guesses
                for (i = 0; i < option; i++)
                {
                    scanf("%d", &input[i]);
                }

                // Check if guesses are correct
                ordered_checker(input, random, option);

                if (guesses == option)
                {
                    correctGuesses = 1;
                    break;
                }
            }
        }
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// function to check for inputed values {DISORDERED}
int disordered_checker(int input[], int random[], int option)
{
    int answer[option];
    int guesses = 0;

    // Initialize answer array
    for (int i = 0; i < option; i++)
    {
        answer[i] = -1;
    }

    for (int i = 0; i < option; i++)
    {
        for (int j = 0; j < option; j++)
        {
            if (input[i] == random[j])
            {
                answer[i] = random[j];
                guesses++;
                break;
            }
        }
    }

    if (guesses == 0)
    {
        for (int i = 0; i < option; i++)
        {
            printf("* ");
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i < option; i++)
        {
            if (answer[i] != -1)
            {
                printf("%d ", answer[i]);
            }
            else
            {
                printf("* ");
            }
        }
        printf("\n");
    }
    // If all guesses are correct, print a congratulatory message
    if (guesses == option)
    {
        printf("Congratulations! You guessed all the numbers correctly!\n");
        // Print the correct numbers
        printf("The correct numbers were: ");
        for (int i = 0; i < option; i++)
        {
            printf("%d ", random[i]);
        }
        printf("\n");
    }
    return guesses;
}

// function to check for inputed values {ORDERED}
int ordered_checker(int input[], int random[], int option)
{
    int guesses = 0;

    // Check if guesses are correct
    for (int i = 0; i < option; i++)
    {
        if (input[i] == random[i])
        {
            printf("%d ", input[i]);
            guesses++;
        }
        else
        {
            printf("* ");
        }
    }
    printf("\n");

    // If all guesses are correct, print a congratulatory message
    if (guesses == option)
    {
        printf("Congratulations! You guessed all the numbers correctly!\n");
        // Print the correct numbers
        printf("The correct numbers were: ");
        for (int i = 0; i < option; i++)
        {
            printf("%d ", random[i]);
        }
        printf("\n");
    }
    return guesses;
}