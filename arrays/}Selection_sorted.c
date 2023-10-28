#include <stdio.h>

int main()
{
    int i, j, temp, min;
    int arr[10];

    printf("Would you insert 10 integer numbers and i will sort them for you: ");

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < 9; i++)
    {
        min = i;

        for(j = i + 1; j < 10; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        if(min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp; 
        }
    }

    printf("Sorted numbers: ");

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}