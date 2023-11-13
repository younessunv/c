#include <stdio.h>

int main()
{
    int arr[10], i = 1;
    int *p = arr;

    printf("insert a list of 10 numbers: ");
    for(p = arr; p < arr + 10; p++)
    {
        printf("Num[%d]: ", i);
        scanf("%d", p);
        i++;
    }

    i = 1;
    printf("\nthe versed list: ");
    for(p = arr + 9; p >= arr; p--)
    {
        printf("\nNum[%d]: %d", i, *p);
        i++;
    }
}