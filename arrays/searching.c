#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int size);
void SelectionSort(int arr[], int size);
void BubbleSort(int arr[], int size);
int binary_Search(int arr[], int size, int target);

int main ()
{
    int n, arr[] = {9, 20, 25, 15, 1, 3, 27, 5, 0, 13, 7, 12, 18, 16, 21, 23, 10, 24};
    const int size = sizeof(arr) / sizeof(arr[0]);

    insertion_Sort(arr, size);

    printf("Enter the desired number in the range of 0 to 30: ");
    scanf("%d", &n);

    int index = binary_Search(arr, size, n);

    if (index != -1) {
        printf("\nWe found your number %d in our list at index: %d.\n", n, index);
    } else {
        printf("\nSorry, your number doesn't exist in our list.\n");
    }

    return 0;
}


void insertionSort (int arr[], int size)
{
    int i, j, key;
    for(i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void SelectionSort (int arr[], int size)
{
    int i, j, mid_indexx, temp;
    for(i = 0; i < size - 1; i++)
    {
        mid_indexx = 1;

        for(j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[mid_indexx])
                mid_indexx = j;
        }

        if(mid_indexx != i)
        {
            temp = arr[i];
            arr[i] = arr[mid_indexx];
            arr[mid_indexx] = temp;
        }
    }
}


void BubbleSort (int arr[], int size)
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


int binary_Search(int arr[], int size, int target)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int midIndex = (low + high) / 2;

        if (target > arr[midIndex])
            low = midIndex + 1;
        else if (target < arr[midIndex])
            high = midIndex - 1;
        else 
            return midIndex; 
    }
    return -1; 
}
