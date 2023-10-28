#include <stdio.h>

int main ()
{
    int n, i, repetetion = 0, size;
    int array[] = {1, 3, 3, 3, 5, 6, 7, 9, 11, 13, 14, 15, 17, 19, 20, 19, 5, 5, 5, 9};

    printf("would you insert a number between 0 and 20 and i'll check if it exists for you: ");
    scanf("%d", &n);

    size = sizeof(array) / sizeof(array[0]);

    for(i = 0; i < size; i++)
    {
        if(array[i] == n)
            repetetion++;
    }

    if(repetetion > 0)
        printf("Yes the number %d exists , and its repeated %d time(s).", n, repetetion);
    else
        printf("the number you inserted does not exist.");

    return 0;
}