#include <stdio.h>

int main()
{   
    int n, i, j, temp;
    int array[] = {9, 20, 25, 15, 1, 3, 27, 5, 0, 13, 7, 12, 18, 16, 21, 23, 10, 24};

    int size = sizeof(array) / sizeof(array[0]);

    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("would you insert the number your looking for between 1 and 30: ");
    scanf("%d", &n);

    int low = 0, high = size - 1;

    while(low <= high)
    {
        int mid_Ind = (low + high) / 2;

        if(array[mid_Ind] > n)
        {
            high = mid_Ind - 1;
        }
        else if(array[mid_Ind] < n)
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
