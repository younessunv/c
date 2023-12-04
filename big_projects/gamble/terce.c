#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_RANDOM_NUMBER 20

void ordered_checker(int input[], int random[], int option);
void disordered_checker(int input[], int random[], int option);
void game();


int main()
{
    char playAgain;

    do
    {
        game();

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain); // Notice the space before %c to consume any previous newline character

    } while (playAgain == 'y' || playAgain == 'Y');

    system("pause");
    return 0;
}

void game()
{
    int i, guesses,input[7], option, attempts, correctGuesses = 0;
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

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*---------------------------------------------------------------DISORDERED:-----------------------------------------------------------------*/

    // working with the case of option 3
    if (strcmp(order, "disordered") == 0)
    {
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
    }

    /*---------------------------------------------------------------ORDERED:-----------------------------------------------------------------*/
    if (strcmp(order, "ordered") == 0)
    {
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
