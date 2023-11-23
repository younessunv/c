#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void checker(int input[], int secretNum[], int option);


int main() {
  int i, option, attempts, correctGuesses = 0;


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
      printf("\nyou can choose how many attempts you wanna play with from 1 to 6: ");
      scanf("%d", &attempts);
    } while (attempts < 1 || attempts > 6);
  } else if (option == 5) {
    do {
      printf("\nyou can choose how many attempts you wanna play with from 1 to 13: ");
      scanf("%d", &attempts);
    } while (attempts < 1 || attempts > 13);
  } else if (option == 7) {
    do {
      printf("\nyou can choose how many attempts you wanna play with from 1 to 19: ");
      scanf("%d", &attempts);
    } while (attempts < 1 || attempts > 19);
  }


  //randomize the number asked to
  srand(time(NULL));
  int random[7];


  for (i = 0; i < option; i++) {
        int newRandom;
        do {
            newRandom = rand() % 20 + 1;
        } while (newRandom == random[0] || newRandom == random[1] || newRandom == random[2]);
        random[i] = newRandom;
    }


  //working with the case of option 3
  if (option == 3) {
    printf("* * *\n");
    while (attempts > 0) {
      int input[3];
      for (int i = 0; i < 3; i++) {
        scanf("%d", &input[i]);
      }


      // Check if guesses are correct
      checker(input, random, option);


      // Check for correct guesses
      if (input[0] == random[0] && input[1] == random[1] && input[2] == random[2]) {
        correctGuesses = 1;
        break;
      }


      attempts--;
    }


    if (correctGuesses) {
      printf("Congratulations! You guessed all the numbers correctly!\n");
      printf("The correct numbers were: %d %d %d\n", random[0], random[1], random[2]);
    } else {
      printf("Sorry, your ran out of attempts.\n");
      printf("The correct numbers were: %d %d %d\n", random[0], random[1], random[2]);
    }
  }


  //working with the case of option 5
 


  //working with the case of option 7
  // ...
}


// function to check for inputed values
void checker(int input[], int secretNum[], int option) {
    int answer[option];
    int guesses = 0;


    // Initialize answer array
    for (int i = 0; i < option; i++) {
        answer[i] = -1;
    }


    for (int i = 0; i < option; i++) {
        for (int j = 0; j < option; j++) {
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


