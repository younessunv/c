#include <stdio.h>
#include <stdlib.h>

int insertion_Sort (int arr[], int size)
{
    

}

int Selection_Sort (int arr[], int size)
{

}

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

int main ()
{
    int i, n;




    
}
