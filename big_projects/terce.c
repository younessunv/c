#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANDOM_NUMBER 30

void checker(int input[], int random[], int option);


int main() {
  int i, input[7], option, attempts, correctGuesses = 0;


  //creating our menu.
  char* menu = "\n1-option: 3\n"
               "2-option: 5\n"
               "3-option: 7\n"
               "Select the number of colones you wish to risk please: ";


  //showing the menu and taking the input
  do {
    printf("%s", menu);
    scanf("%d", &option);
  } while (option != 3 && option != 5 && option != 7);


  //asking the user for how many attempts to play
  if (option == 3) {
    do {
      printf("\nyou can choose how many attempts you wanna play with from 1 to 13: ");
      scanf("%d", &attempts);
    } while (attempts < 1 || attempts > 18);
  } else if (option == 5) {
    do {
      printf("\nyou can choose how many attempts you wanna play with from 1 to 8: ");
      scanf("%d", &attempts);
    } while (attempts < 1 || attempts > 8);
  } else if (option == 7) {
    do {
      printf("\nyou can choose how many attempts you wanna play with from 1 to 5: ");
      scanf("%d", &attempts);
    } while (attempts < 1 || attempts > 6);
  }


  //randomize the number asked to
  srand(time(NULL));
  int random[7];

    for (i = 0; i < option; i++) {
        int newRandom;
        int duplicate;
        do {
            duplicate = 0;
            newRandom = rand() % MAX_RANDOM_NUMBER + 1;

            // Check for duplicates within the generated numbers
            for (int j = 0; j < i; j++) {
                if (newRandom == random[j]) {
                    duplicate = 1;
                    break;
                }
            }
        } while (duplicate);

        random[i] = newRandom;
    }



  //working with the case of option 3

  if (option == 3) {
        printf("* * *\n");
        while (attempts > 0) {
            // Get user guesses
            for (i = 0; i < option; i++) {
                scanf("%d", &input[i]);
            }

            // Check if guesses are correct
            checker(input, random, option);

            attempts--;

            if ((input[0] == random[0] || input[0] == random[1] || input[0] == random[2])
                && (input[1] == random[0] || input[1] == random[1] || input[1] == random[2])
                && (input[2] == random[0] || input[2] == random[1] || input[2] == random[2]))
            {
                correctGuesses = 1;
                break;
            }
        }

        // Print the congratulatory message outside the loop
        if (correctGuesses) {
            printf("Congratulations! You guessed all the numbers correctly!\n");
            printf("The correct numbers were: %d %d %d\n", random[0], random[1], random[2]);
        } else {
            printf("Sorry, your guesses are incorrect.\n");
            printf("The correct numbers were: %d %d %d\n", random[0], random[1], random[2]);
        }
  }


  //working with the case of option 5
  if (option == 5) {
        printf("* * * * *\n");
        while (attempts > 0) {
            // Get user guesses
            for (i = 0; i < option; i++) {
                scanf("%d", &input[i]);
            }

            // Check if guesses are correct
            checker(input, random, option);

            attempts--;

            if ((input[0] == random[0] || input[0] == random[1] || input[0] == random[2] || input[0] == random[3] ||input[0] == random[4])
                && (input[1] == random[0] || input[1] == random[1] || input[1] == random[2] || input[1] == random[3] || input[1] == random[4])
                && (input[2] == random[0] || input[2] == random[1] || input[2] == random[2] || input[2] == random[3] || input[2] == random[4])
                && (input[3] == random[0] || input[3] == random[1] || input[3] == random[2] || input[3] == random[3] || input[3] == random[4])
                && (input[4] == random[0] || input[4] == random[1] || input[4] == random[2] || input[4] == random[3] || input[4] == random[4])
                )
            {
                correctGuesses = 1;
                break;
            }
        }

        // Print the congratulatory message outside the loop
        if (correctGuesses) {
            printf("Congratulations! You guessed all the numbers correctly!\n");
            printf("The correct numbers were: %d %d %d %d %d\n", random[0], random[1], random[2], random[3], random[4]);
        } else {
            printf("Sorry, your guesses are incorrect.\n");
            printf("The correct numbers were: %d %d %d %d %d\n", random[0], random[1], random[2], random[3], random[4]);
        }
  }
 

  //working with the case of option 7
    if (option == 7) {
        printf("* * * * * * *\n");
        while (attempts > 0) {
            // Get user guesses
            for (i = 0; i < option; i++) {
                scanf("%d", &input[i]);
            }

            // Check if guesses are correct
            checker(input, random, option);

            attempts--;

            if ((input[0] == random[0] || input[0] == random[1] || input[0] == random[2] || input[0] == random[3] ||input[0] == random[4] || input[0] == random[5] ||input[0] == random[6])
                && (input[1] == random[0] || input[1] == random[1] || input[1] == random[2] || input[1] == random[3] ||input[1] == random[4] || input[1] == random[5] ||input[1] == random[6])
                && (input[2] == random[0] || input[2] == random[1] || input[2] == random[2] || input[2] == random[3] ||input[2] == random[4] || input[2] == random[5] ||input[2] == random[6])
                && (input[3] == random[0] || input[3] == random[1] || input[3] == random[2] || input[3] == random[3] ||input[3] == random[4] || input[3] == random[5] ||input[3] == random[6])
                && (input[4] == random[0] || input[4] == random[1] || input[4] == random[2] || input[4] == random[3] ||input[4] == random[4] || input[4] == random[5] ||input[4] == random[6])
                && (input[5] == random[0] || input[5] == random[1] || input[5] == random[2] || input[5] == random[3] ||input[5] == random[4] || input[5] == random[5] ||input[5] == random[6])
                && (input[6] == random[0] || input[6] == random[1] || input[6] == random[2] || input[6] == random[3] ||input[6] == random[4] || input[6] == random[5] ||input[6] == random[6])
                )
            {
                correctGuesses = 1;
                break;
            }
        }

        // Print the congratulatory message outside the loop
        if (correctGuesses) {
            printf("Congratulations! You guessed all the numbers correctly!\n");
            printf("The correct numbers were: %d %d %d %d %d %d %d\n", random[0], random[1], random[2], random[3], random[4],random[5], random[6]);
        } else {
            printf("Sorry, your guesses are incorrect.\n");
            printf("The correct numbers were: %d %d %d %d %d %d %d\n", random[0], random[1], random[2], random[3], random[4], random[5], random[6]);
        }
  }
  
  return 0;
}


// function to check for inputed values
void checker(int input[], int random[], int option) {
    int answer[option];
    int guesses = 0;


    // Initialize answer array
    for (int i = 0; i < option; i++) {
        answer[i] = -1;
    }

    for (int i = 0; i < option; i++) {
        for (int j = 0; j < option; j++) {
            if (input[i] == random[j]) {
                answer[i] = random[j];
                guesses++;
                break;
            }
        }
    }


    if (guesses == 0) {
        for(int i = 0; i < option; i++){
            printf("* ");
        }
        printf("\n");
    } else {
        for (int i = 0; i < option; i++) {
            if (answer[i] != -1) {
                printf("%d ", answer[i]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}