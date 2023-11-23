#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 3

void checker(int input[], int secretNum[]);

int main() {
    int i, secretNum[ARRAY_SIZE];
    int input[ARRAY_SIZE], attempts = 6, correctGuesses = 0;

    // Generate random numbers
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        int newRandom;
        do {
            newRandom = rand() % 10 + 1;
        } while (newRandom == secretNum[0] || newRandom == secretNum[1] || newRandom == secretNum[2]);
        secretNum[i] = newRandom;
    }


    printf("* * *\n");
    while (attempts > 0) {
        // Get user guesses
        for (i = 0; i < ARRAY_SIZE; i++) {
            scanf("%d", &input[i]);
        }

        // Check if guesses are correct
        checker(input, secretNum);

        attempts--;

        if ((input[0] == secretNum[0] || input[0] == secretNum[1] || input[0] == secretNum[2])
            && (input[1] == secretNum[0] || input[1] == secretNum[1] || input[1] == secretNum[2])
            && (input[2] == secretNum[0] || input[2] == secretNum[1] || input[2] == secretNum[2]))
        {
            correctGuesses = 1;
            break;
        }
    }

    // Print the congratulatory message outside the loop
    if (correctGuesses) {
        printf("Congratulations! You guessed all the numbers correctly!\n");
        printf("The correct numbers were: %d %d %d\n", secretNum[0], secretNum[1], secretNum[2]);
    } else {
        printf("Sorry, your guesses are incorrect.\n");
        printf("The correct numbers were: %d %d %d\n", secretNum[0], secretNum[1], secretNum[2]);
    }

    return 0;
}

void checker(int input[], int secretNum[]) {
    int answer[ARRAY_SIZE] = {-1, -1, -1}, guesses = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            if (input[i] == secretNum[j]) {
                answer[i] = secretNum[j];
                guesses++;
                break;
            }
        }
    }

    if (guesses == 0) {
        printf("* * *\n");
    } else {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (answer[i] != -1) {
                printf("%d ", answer[i]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}