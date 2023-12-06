#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_RANDOM_NUMBER 20

void game();
void ordered_checker(int input[], int random[], int option);
void disordered_checker(int input[], int random[], int option);
void sign_up();
void sign_in();
void clearScreen();


int main()
{
    int option_menu, option_sign;
    char *start = "1-Sign in\n"
                  "2-Sign up\n";

    char *menu = "\n1- Play\n"
                 "2- info\n"
                 "3- top scores\n"
                 "4- Exit\n";
    ////////////////////////////////////////////////////////////:Sing up / Sign in://////////////////////////////////////////////////////////////
    do
    {
        printf("%s", start);
        scanf("%d", &option_sign);
        clearScreen();
    } while (option_sign != 1 && option_sign != 2);
    
    ///////////////////////////////////////////sign in:


    ///////////////////////////////////////////sign up:



    printf("%s", menu);
    scanf("%d", &option_menu);
    clearScreen();

    while(option_menu == 1)
    {
        game();

        printf("%s", menu);
        scanf("%d", &option_menu);
        clearScreen(); 

    }

    system("pause");
    return 0;
}

void game()
{
    int i, guesses,input[7], option, attempts, correctGuesses = 0;
    char order[20];

    // creating our menu.
    char *menu = "\n-option: 3\n"
                 "-option: 5\n"
                 "-option: 7\n"
                 "Select the number of colones you wish to risk please: ";

    // choosing an option of two {ordered/ disordered}
    do
    {
        printf("\nchoose which mode you wanna play, insert {ordered / disordered}:\n");
        scanf("%s", order);
        clearScreen();
    } while (strcmp(order, "ordered") != 0 && strcmp(order, "disordered") != 0);

    clearScreen();

    // showing the menu and taking the input
    do
    {
        printf("%s", menu);
        scanf("%d", &option);
        clearScreen();
    } while (option != 3 && option != 5 && option != 7);

    clearScreen();

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

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*---------------------------------------------------------------DISORDERED:-----------------------------------------------------------------*/

    // working with the case of option 3
    if (strcmp(order, "disordered") == 0)
    {
        printf("------------------------------DISORDERED:----------------------------\n");
        if (option == 3)
        {
            printf("* * *\n");
            while (correctGuesses != 1)
            {
                // Get user guesses
                for (i = 0; i < option; i++)
                {
                    scanf("%d", &input[i]);
                }

                // Check if guesses are correct
                disordered_checker(input, random, option);

                if ((input[0] == random[0] || input[0] == random[1] || input[0] == random[2])
                && (input[1] == random[0] || input[1] == random[1] || input[1] == random[2])
                && (input[2] == random[0] || input[2] == random[1] || input[2] == random[2]))
                {
                    correctGuesses = 1;
                    break;
                }
            }

            if (correctGuesses) {
                printf("Congratulations! You guessed all the numbers correctly!\n");
                printf("The correct numbers were: %d %d %d\n", random[0], random[1], random[2]);
            }
        }

        // working with the case of option 5
        if (option == 5)
        {
            printf("* * * * *\n");
            while (correctGuesses != 1)
            {
                // Get user guesses
                for (i = 0; i < option; i++)
                {
                    scanf("%d", &input[i]);
                }

                // Check if guesses are correct
                disordered_checker(input, random, option);

                if ((input[0] == random[0] || input[0] == random[1] || input[0] == random[2] || input[0] == random[3] ||input[0] == random[4])
                    && (input[1] == random[0] || input[1] == random[1] || input[1] == random[2] || input[1] == random[3] || input[1] == random[4])
                    && (input[2] == random[0] || input[2] == random[1] || input[2] == random[2] || input[2] == random[3] || input[2] == random[4])
                    && (input[3] == random[0] || input[3] == random[1] || input[3] == random[2] || input[3] == random[3] || input[3] == random[4])
                    && (input[4] == random[0] || input[4] == random[1] || input[4] == random[2] || input[4] == random[3] || input[4] == random[4]))
                {
                    correctGuesses = 1;
                    break;
                }
            }
            if (correctGuesses) {
                printf("Congratulations! You guessed all the numbers correctly!\n");
                printf("The correct numbers were: %d %d %d %d %d\n", random[0], random[1], random[2], random[3], random[4]);
            }
        }

        // working with the case of option 7
        if (option == 7)
        {
            printf("* * * * * * *\n");
            while (correctGuesses != 1)
            {
                // Get user guesses
                for (i = 0; i < option; i++)
                {
                    scanf("%d", &input[i]);
                }

                // Check if guesses are correct
                disordered_checker(input, random, option);

                 if ((input[0] == random[0] || input[0] == random[1] || input[0] == random[2] || input[0] == random[3] ||input[0] == random[4] || input[0] == random[5] ||input[0] == random[6])
                    && (input[1] == random[0] || input[1] == random[1] || input[1] == random[2] || input[1] == random[3] ||input[1] == random[4] || input[1] == random[5] ||input[1] == random[6])
                    && (input[2] == random[0] || input[2] == random[1] || input[2] == random[2] || input[2] == random[3] ||input[2] == random[4] || input[2] == random[5] ||input[2] == random[6])
                    && (input[3] == random[0] || input[3] == random[1] || input[3] == random[2] || input[3] == random[3] ||input[3] == random[4] || input[3] == random[5] ||input[3] == random[6])
                    && (input[4] == random[0] || input[4] == random[1] || input[4] == random[2] || input[4] == random[3] ||input[4] == random[4] || input[4] == random[5] ||input[4] == random[6])
                    && (input[5] == random[0] || input[5] == random[1] || input[5] == random[2] || input[5] == random[3] ||input[5] == random[4] || input[5] == random[5] ||input[5] == random[6])
                    && (input[6] == random[0] || input[6] == random[1] || input[6] == random[2] || input[6] == random[3] ||input[6] == random[4] || input[6] == random[5] ||input[6] == random[6]))
                {
                    correctGuesses = 1;
                    break;
                }
            }

            if (correctGuesses) {
                printf("Congratulations! You guessed all the numbers correctly!\n");
                printf("The correct numbers were: %d %d %d %d %d %d %d\n", random[0], random[1], random[2], random[3], random[4],random[5], random[6]);
            }
        }
        system("pause");
        clearScreen();
        
    }

    /*---------------------------------------------------------------ORDERED:-----------------------------------------------------------------*/
    if (strcmp(order, "ordered") == 0)
    {
        printf("------------------------------ORDERED:----------------------------\n");
        // working with the case of option 3
        if (option == 3)
        {
            printf("* * *\n");
            while (correctGuesses != 1)
            {
                // Get user guesses
                for (i = 0; i < option; i++)
                {
                    scanf("%d", &input[i]);
                }

                // Check if guesses are correct
                ordered_checker(input, random, option);

                if (input[0] == random[0] && input[1] == random[1] && input[2] == random[2])
                {
                    correctGuesses = 1;
                    break;
                }
            }
            if (correctGuesses) {
                printf("Congratulations! You guessed all the numbers correctly!\n");
                printf("The correct numbers were: %d %d %d\n", random[0], random[1], random[2]);
            }
        }

        // working with the case of option 5
        if (option == 5)
        {
            printf("* * * * *\n");
            while (correctGuesses != 1)
            {
                // Get user guesses
                for (i = 0; i < option; i++)
                {
                    scanf("%d", &input[i]);
                }

                // Check if guesses are correct
                ordered_checker(input, random, option);

                if (input[0] == random[0] && input[1] == random[1] && input[2] == random[2] &&  input[3] == random[3] && input[4] == random[4])
                {
                    correctGuesses = 1;
                    break;
                }
            }
            if (correctGuesses) {
                printf("Congratulations! You guessed all the numbers correctly!\n");
                printf("The correct numbers were: %d %d %d %d %d\n", random[0], random[1], random[2], random[3], random[4]);
            }
        }

        // working with the case of option 7
        if (option == 7)
        {
            printf("* * * * * * *\n");
            while (correctGuesses != 1)
            {
                // Get user guesses
                for (i = 0; i < option; i++)
                {
                    scanf("%d", &input[i]);
                }

                // Check if guesses are correct
                ordered_checker(input, random, option);

                if (input[0] == random[0] && input[1] == random[1] && input[2] == random[2] &&  input[3] == random[3] && input[4] == random[4] && input[5] == random[5] && input[6] == random[6])
                {
                    correctGuesses = 1;
                    break;
                }
            }
            if (correctGuesses) {
                printf("Congratulations! You guessed all the numbers correctly!\n");
                printf("The correct numbers were: %d %d %d %d %d %d %d\n", random[0], random[1], random[2], random[3], random[4],random[5], random[6]);
            }
        }
        system("pause");
        clearScreen();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// function to check for inputed values {DISORDERED}
void disordered_checker(int input[], int random[], int option)
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
}

// function to check for inputed values {ORDERED}
void ordered_checker(int input[], int random[], int option)
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
}

void clearScreen()
{
    system("cls"); // Clear screen on Windows
}
