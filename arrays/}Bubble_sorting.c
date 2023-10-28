#include <stdio.h>

int main()
{
    int i, j, temp;
    int array[10];

    printf("Would you insert 10 integer numbers and i will sort them for you: ");

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
    }

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 10 - i; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("Sorted numbers: ");

    for(i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}