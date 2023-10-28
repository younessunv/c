#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, x,guess = 0;
    srand(time(NULL));
    int random = (rand() % 31);

    printf("would you choose a number between 0 and 30 , you have 5 attempts: ");

    for(i = 1; i <= 5; i++)
    {
        scanf("%d", &x);
        if(x == random)
        {
            guess = 1;
            break;
        }
        else if(x < random)
        {
            printf("No it's above that , try again: ");
        }
        else if(x > random)
        {
            printf("No it's below that , try again: ");
        }
    }
    if(guess == 1)
        printf("Congrats you're right the number is %d and you got in your %d attempt.", x, i);
    else
        printf("Sorry but you lost all your attempts the number was %d , you can play again!", random);
    return 0;
}