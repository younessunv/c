#include <stdio.h>
#include <stdlib.h>

int Bubble_Sort (int arr[], int size)
{
    int i, j, temp;
    for(i = 0; i < size - 1; i++ )
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                }
            }

        }
    }

int main()
{
    int i, n;
    int arr[] = {9, 20, 25, 15, 1, 3, 27, 5, 0, 13, 7, 12, 18, 16, 21, 23, 10, 24};
    int size = sizeof(arr) / sizeof(arr[0]);

    Bubble_Ssort(arr, size);

    printf("\nwould you insert the number your looking for between 1 and 30: ");
    scanf("%d", &n);

    int low = 0, high = size - 1;

    while(low <= high)
    {
        int mid_Ind = (low + high) / 2;

        if(arr[mid_Ind] > n)
        {
            high = mid_Ind - 1;
        }
        else if(arr[mid_Ind] < n)
        {
            low = mid_Ind + 1;
        }
        else
        {
            printf("we find the number %d at index %d.", n, mid_Ind);
            return 0;
        }
    }

    printf("We didn't find the number you're looking for.");

    return 0;
}
